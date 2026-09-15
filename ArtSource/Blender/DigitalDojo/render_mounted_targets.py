import bpy
from pathlib import Path
from mathutils import Vector
source=Path(__file__).resolve().parent
bpy.ops.wm.open_mainfile(filepath=str(source/'MountedTargetKit.blend'))
names=['MountedPunchTarget','MountedKickTarget','MountedHeavyTarget','MountedHeavyKickTarget']
for i,name in enumerate(names):bpy.data.objects[name].location=((i-1.5)*2.8,0,0)
for name in ['MountArm','MountPlate']:
 for obj in [bpy.data.objects[name]]+list(bpy.data.objects[name].children_recursive):obj.hide_render=True
bpy.ops.object.camera_add(location=(0,-15,2));camera=bpy.context.object
camera.rotation_euler=(Vector((0,0,0))-camera.location).to_track_quat('-Z','Y').to_euler();camera.data.type='ORTHO';camera.data.ortho_scale=11.5
scene=bpy.context.scene;scene.camera=camera;scene.render.engine='CYCLES';scene.cycles.samples=24
for pos,power in [((-4,-6,5),1800),((4,-3,3),1400)]:
 bpy.ops.object.light_add(type='AREA',location=pos);lamp=bpy.context.object;lamp.data.energy=power;lamp.data.shape='DISK';lamp.data.size=5;lamp.rotation_euler=(Vector((0,0,0))-lamp.location).to_track_quat('-Z','Y').to_euler()
scene.world.color=(.1,.1,.1);scene.render.resolution_x=1800;scene.render.resolution_y=650;scene.render.resolution_percentage=100;scene.render.image_settings.file_format='PNG';scene.render.filepath=str(source/'mounted-asset-review.png');bpy.ops.render.render(write_still=True)
