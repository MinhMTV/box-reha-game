import bpy
from pathlib import Path
src=Path(__file__).resolve().parent/'ReferenceRefinement'
project=Path(__file__).resolve().parents[3]
bpy.ops.wm.open_mainfile(filepath=str(src/'MountedTargetKit.blend'))
for o in list(bpy.data.objects):bpy.data.objects.remove(o,do_unlink=True)
bpy.ops.mesh.primitive_plane_add(size=2);plane=bpy.context.object
scene=bpy.context.scene;scene.render.engine='CYCLES';scene.cycles.samples=1
for key in ['MatteBlack','MetalDark','Padding']:
    mat=bpy.data.materials['M_DD_'+key];plane.data.materials.clear();plane.data.materials.append(mat)
    image=bpy.data.images.new(key+'Normal',width=512,height=512,alpha=False);image.colorspace_settings.name='Non-Color'
    node=mat.node_tree.nodes.new('ShaderNodeTexImage');node.image=image;mat.node_tree.nodes.active=node
    bpy.ops.object.bake(type='NORMAL')
    image.filepath_raw=str(project/'Assets/Art/DigitalDojo/Textures'/('M_DD_'+key+'_Normal.png'));image.file_format='PNG';image.save()
print('TARGET_NORMAL_BAKES_COMPLETE')
