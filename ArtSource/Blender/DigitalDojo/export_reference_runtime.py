"""Bake approved Blender room lighting into one mobile atlas and export editable target meshes."""
import bpy, json
from pathlib import Path
src=Path(__file__).resolve().parent/'ReferenceRefinement'
project=Path(__file__).resolve().parents[3]
models=project/'Assets/Art/DigitalDojo/Models';textures=project/'Assets/Art/DigitalDojo/Textures';textures.mkdir(exist_ok=True)
bpy.ops.wm.open_mainfile(filepath=str(src/'ReferenceDojo.blend'))
scene=bpy.context.scene;scene.render.engine='CYCLES';scene.cycles.samples=16;scene.cycles.use_denoising=True
objects=[o for o in bpy.data.objects if o.type=='MESH']
bpy.ops.object.select_all(action='DESELECT')
for o in objects:o.select_set(True)
bpy.context.view_layer.objects.active=objects[0];bpy.ops.object.join();room=bpy.context.object;room.name='ReferenceRoomMesh'
# Preserve world space when removing the authored root.
world=room.matrix_world.copy();room.parent=None;room.matrix_world=world
bpy.ops.object.transform_apply(location=True,rotation=True,scale=True)
bpy.ops.object.mode_set(mode='EDIT');bpy.ops.mesh.select_all(action='SELECT');bpy.ops.uv.smart_project(angle_limit=1.15,island_margin=.003);bpy.ops.object.mode_set(mode='OBJECT')
im=bpy.data.images.new('DojoRoomBaked',width=4096,height=4096,alpha=False)
for mat in room.data.materials:
    node=mat.node_tree.nodes.new('ShaderNodeTexImage');node.image=im;mat.node_tree.nodes.active=node
scene.render.bake.margin=8
bpy.ops.object.bake(type='COMBINED')
im.filepath_raw=str(textures/'DojoRoomBaked.png');im.file_format='PNG';im.save()
# One material/draw for the static room; runtime lighting must not illuminate the bake twice.
mat=bpy.data.materials.new('M_DD_RoomBaked');mat.use_nodes=True
room.data.materials.clear();room.data.materials.append(mat)
for poly in room.data.polygons:poly.material_index=0
bpy.ops.export_scene.fbx(filepath=str(models/'ReferenceRoom.fbx'),use_selection=True,object_types={'MESH'},bake_anim=False,axis_forward='-Z',axis_up='Y',apply_unit_scale=True)
# Export the approved target design without duplicate fixed authoring stands.
import sys
if '--runtime' not in sys.argv:sys.argv.append('--runtime')
script=Path(__file__).parent/'generate_reference_targets.py'
exec(compile(script.read_text(encoding='utf-8'),str(script),'exec'),{'__file__':str(script),'__name__':'__main__'})
print('REFERENCE_RUNTIME_EXPORT_COMPLETE')
