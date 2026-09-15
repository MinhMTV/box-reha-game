"""Blender keyframe counterpart of the mechanical target phase specification."""
import bpy, math, json
from pathlib import Path
from mathutils import Vector
source=Path(__file__).resolve().parent/'ReferenceRefinement'
bpy.ops.wm.open_mainfile(filepath=str(source/'MountedTargetKit.blend'))
scene=bpy.context.scene;scene.frame_start=1;scene.frame_end=120;scene.render.fps=30
names=['MountedPunchTarget','MountedKickTarget','MountedHeavyTarget','MountedHeavyKickTarget']
for name in ['MountArm','MountPlate']:
    for o in [bpy.data.objects[name]]+list(bpy.data.objects[name].children_recursive):o.hide_render=True
for i,name in enumerate(names):
    obj=bpy.data.objects[name];base=(i-1.5)*3.3
    for frame,y,yaw in [(1,.8,65),(4,.8,65),(22,0,0),(60,-.8,0),(65,-.65,-4),(72,-.8,0),(95,-.8,0),(120,-.8,0)]:
        obj.location=(base,y,.1);obj.rotation_euler[2]=math.radians(yaw);obj.keyframe_insert(data_path='location',frame=frame);obj.keyframe_insert(data_path='rotation_euler',frame=frame)
    for j,o in enumerate([x for x in obj.children_recursive if x.name.startswith('FracturePiece_')]):
        rest=o.location.copy();o.keyframe_insert(data_path='location',frame=72);o.keyframe_insert(data_path='rotation_euler',frame=72)
        a=j*2.399963;o.location=rest+Vector((math.cos(a)*.42,-.30,math.sin(a)*.42));o.rotation_euler=(.3,.2,(-1 if j%2 else 1)*.5);o.keyframe_insert(data_path='location',frame=95);o.keyframe_insert(data_path='rotation_euler',frame=95)
for name,frame in [('IDLE',1),('DEPLOY',12),('TRAVEL',40),('IMPACT',65),('BREAK',95)]:scene.timeline_markers.new(name,frame=frame)
bpy.ops.object.camera_add(location=(1,-17,3));cam=bpy.context.object;cam.rotation_euler=(Vector((0,0,0))-cam.location).to_track_quat('-Z','Y').to_euler();cam.data.type='ORTHO';cam.data.ortho_scale=13.6;scene.camera=cam
for pos,power in [((-5,-5,6),700),((5,-3,4),450)]:
    bpy.ops.object.light_add(type='AREA',location=pos);lamp=bpy.context.object;lamp.data.energy=power;lamp.data.size=5;lamp.rotation_euler=(Vector((0,0,0))-lamp.location).to_track_quat('-Z','Y').to_euler()
scene.world.color=(.025,.025,.025);scene.render.engine='CYCLES';scene.cycles.samples=24;scene.cycles.use_denoising=True;scene.render.resolution_x=1800;scene.render.resolution_y=600;scene.render.resolution_percentage=100
scene.frame_set(40);bpy.ops.wm.save_as_mainfile(filepath=str(source/'TargetAnimationReview.blend'))
for name,frame in [('idle',1),('deploy',12),('travel',40),('impact',65),('break',95)]:
    scene.frame_set(frame);scene.render.filepath=str(source/('animation-'+name+'.png'));bpy.ops.render.render(write_still=True)
(source/'animation-phases.json').write_text(json.dumps({'fps':30,'frames':120,'markers':{'idle':1,'deploy':12,'travel':40,'impact':65,'break':95},'runtime':'TargetMountMotion + DigitalDojoTargetVisual','review':'authoring motion; runtime camera and baked asset validation pending'},indent=2),encoding='utf-8')
