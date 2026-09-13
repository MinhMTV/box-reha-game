"""Run: blender --background --python ArtSource/Blender/DigitalDojo/generate_dojo.py
Meters; +Z up in Blender; front faces -Y; FBX converts to Unity Y-up.
Original geometry. No external textures or third-party assets.
"""
import bpy, math, json
from pathlib import Path
from mathutils import Vector

ROOT = Path(__file__).resolve().parents[3]
SOURCE = ROOT / 'ArtSource/Blender/DigitalDojo'
EXPORT = ROOT / 'Assets/Art/DigitalDojo/Models'
EXPORT.mkdir(parents=True, exist_ok=True)
bpy.ops.object.select_all(action='SELECT'); bpy.ops.object.delete(use_global=False)
for mat in list(bpy.data.materials): bpy.data.materials.remove(mat)
COLORS = {
 'MatteBlack': (0.026,0.029,0.032,1), 'MetalDark': (0.09,0.10,0.115,1),
 'Padding': (0.12,0.13,0.145,1), 'White': (0.86,0.83,0.77,1),
 'RedAccent': (0.65,0.045,0.028,1), 'BlueAccent': (0.07,0.29,0.48,1),
 'EmissiveRed': (0.95,0.12,0.075,1), 'EmissiveBlue': (0.15,0.52,0.78,1),
 'Wood_Dark': (0.16,0.082,0.037,1), 'Concrete': (0.075,0.081,0.085,1),
 'WarmLight': (0.9,0.63,0.34,1)
}
MATS={}
for key,color in COLORS.items():
    mat=bpy.data.materials.new('M_DD_'+key); mat.diffuse_color=color; mat.use_nodes=True
    bsdf=mat.node_tree.nodes.get('Principled BSDF'); bsdf.inputs['Base Color'].default_value=color
    bsdf.inputs['Roughness'].default_value=0.65 if key!='MetalDark' else 0.36
    bsdf.inputs['Metallic'].default_value=0.65 if key=='MetalDark' else 0
    if key.startswith('Emissive') or key=='WarmLight':
        bsdf.inputs['Emission Color'].default_value=color; bsdf.inputs['Emission Strength'].default_value=0.65
    MATS[key]=mat

def root(name):
    obj=bpy.data.objects.new(name,None); bpy.context.collection.objects.link(obj); return obj
def finish(obj,name,parent,mat,bevel=0):
    obj.name=name; obj.parent=parent; obj.data.materials.append(MATS[mat])
    bpy.context.view_layer.objects.active=obj
    bpy.ops.object.transform_apply(location=False,rotation=False,scale=True)
    if bevel:
        modifier=obj.modifiers.new('Edge softness','BEVEL'); modifier.width=bevel; modifier.segments=3
        bpy.ops.object.modifier_apply(modifier=modifier.name)
    for polygon in obj.data.polygons: polygon.use_smooth=False
    return obj
def box(parent,name,loc,size,mat,bevel=0.025):
    bpy.ops.mesh.primitive_cube_add(size=1,location=loc)
    obj=bpy.context.object; obj.scale=size; return finish(obj,name,parent,mat,bevel)
def disc(parent,name,radius,depth,y,mat,vertices=48):
    bpy.ops.mesh.primitive_cylinder_add(vertices=vertices,radius=radius,depth=depth,location=(0,y,0),rotation=(math.pi/2,0,0))
    return finish(bpy.context.object,name,parent,mat,0.014)
def ring(parent,name,radius,tube,y,mat):
    bpy.ops.mesh.primitive_torus_add(major_segments=48,minor_segments=6,major_radius=radius,minor_radius=tube,location=(0,y,0),rotation=(math.pi/2,0,0))
    obj=finish(bpy.context.object,name,parent,mat)
    for p in obj.data.polygons:p.use_smooth=True
    return obj

assets=[]
p=root('PunchTarget'); assets.append(p)
disc(p,'Frame',0.83,0.14,0.09,'MetalDark',8)
disc(p,'RearHousing',0.72,0.2,0.18,'MatteBlack')
disc(p,'OuterPadding',0.75,0.22,-0.05,'Padding')
ring(p,'OuterRing',0.68,0.045,-0.185,'RedAccent')
ring(p,'InnerRing',0.46,0.017,-0.187,'White')
disc(p,'Core',0.39,0.045,-0.185,'MatteBlack')
ring(p,'EmissiveAccent',0.25,0.018,-0.215,'EmissiveRed')
box(p,'CenterMark',(0,-0.222,0),(0.035,0.015,0.11),'White',0.006)

k=root('KickTarget'); assets.append(k)
box(k,'Frame',(0,0.07,0),(1.12,0.19,1.62),'MetalDark',0.1)
box(k,'RearHousing',(0,0.17,0),(0.9,0.2,1.38),'MatteBlack',0.08)
box(k,'Border',(0,-0.055,0),(1.03,0.15,1.52),'BlueAccent',0.09)
box(k,'Padding',(0,-0.145,0),(0.92,0.16,1.39),'Padding',0.1)
box(k,'ImpactPanel',(0,-0.23,0),(0.68,0.04,1.02),'MatteBlack',0.08)
box(k,'EmissiveAccent',(0,-0.261,0.37),(0.4,0.02,0.024),'EmissiveBlue',0.008)
box(k,'FootSole',(0,-0.264,-0.06),(0.16,0.02,0.36),'White',0.065)
box(k,'FootHeel',(0,-0.264,-0.32),(0.13,0.02,0.12),'White',0.05)

h=root('HeavyTarget'); assets.append(h)
disc(h,'StructuralFrame',1.02,0.18,0.12,'MetalDark',8)
disc(h,'RearHousing',0.89,0.28,0.23,'MatteBlack',32)
disc(h,'OuterPadding',0.94,0.3,-0.03,'Padding')
ring(h,'RingOuter',0.86,0.052,-0.22,'RedAccent')
ring(h,'RingMiddle',0.62,0.027,-0.223,'White')
ring(h,'RingInner',0.39,0.022,-0.24,'MetalDark')
disc(h,'Core',0.32,0.06,-0.23,'MatteBlack')
ring(h,'CoreAccent',0.23,0.018,-0.27,'EmissiveRed')
segments=root('DamageSegments'); segments.parent=h
for i in range(8):
    a=i*math.pi/4
    obj=box(segments,'DamageSegment_%02d'%i,(math.sin(a)*0.77,-0.25,math.cos(a)*0.77),(0.17,0.045,0.06),'EmissiveRed',0.014)
    obj.rotation_euler[1]=a

for name,kind in [('WallPanel_A','wall'),('WoodSlatPanel','slat'),('FloorPanel','floor'),('WoodenBeam','beam'),('LightStripHousing','light'),('TrainingFrame','frame')]:
    r=root(name); assets.append(r)
    if kind=='wall':
        box(r,'Concrete',(0,0.07,1.5),(2.0,0.14,3.0),'Concrete',0.025)
        for x in [-0.95,0.95]:box(r,'Edge',(x,-0.02,1.5),(0.025,0.05,2.9),'MetalDark',0.008)
    elif kind=='slat':
        box(r,'Backing',(0,0.08,1.5),(2,0.1,3),'MatteBlack',0.01)
        for i in range(12):box(r,'Slat_%02d'%i,(-0.92+i*0.166,0,1.5),(0.065,0.12,3),'Wood_Dark',0.008)
    elif kind=='floor':
        for i in range(5):box(r,'Board_%02d'%i,(-0.8+i*0.4,0,-0.035),(0.394,2,0.07),'Wood_Dark',0.008)
    elif kind=='beam':box(r,'Beam',(0,0,1.5),(0.18,0.2,3),'Wood_Dark',0.012)
    elif kind=='light':
        box(r,'Housing',(0,0,0),(1.8,0.12,0.1),'MetalDark',0.015)
        box(r,'Diffuser',(0,-0.07,0),(1.68,0.035,0.045),'WarmLight',0.008)
    else:
        for x in [-1.25,1.25]:box(r,'Upright',(x,0,1.5),(0.12,0.16,3),'MetalDark',0.02)
        box(r,'Crossbar',(0,0,3),(2.6,0.16,0.12),'MetalDark',0.02)

inventory=[]
for asset in assets:
    objects=[asset]+list(asset.children_recursive)
    bpy.ops.object.select_all(action='DESELECT')
    for obj in objects:obj.select_set(True)
    bpy.context.view_layer.objects.active=asset
    triangles=0
    for obj in objects:
        if obj.type=='MESH':obj.data.calc_loop_triangles();triangles+=len(obj.data.loop_triangles)
    inventory.append({'name':asset.name,'triangles':triangles,'meshes':sum(o.type=='MESH' for o in objects),'meters':True,'front':'-Y Blender / -Z Unity','origin':'target center; room module floor center'})
    bpy.ops.export_scene.fbx(filepath=str(EXPORT/(asset.name+'.fbx')),use_selection=True,object_types={'EMPTY','MESH'},add_leaf_bones=False,bake_anim=False,axis_forward='-Z',axis_up='Y',apply_unit_scale=True,use_mesh_modifiers=True)

SOURCE.mkdir(parents=True,exist_ok=True)
(SOURCE/'inventory.json').write_text(json.dumps(inventory,indent=2))
bpy.ops.wm.save_as_mainfile(filepath=str(SOURCE/'DigitalDojoKit.blend'))
# Contact sheet is a Blender asset review, not a gameplay screenshot.
for i,asset in enumerate(assets):asset.location=(i%3*3.8,0,-(i//3)*4.0)
bpy.ops.object.camera_add(location=(4,-24,0.5)); camera=bpy.context.object
camera.rotation_euler=(Vector((3.8,0,-4.3))-camera.location).to_track_quat('-Z','Y').to_euler()
camera.data.type='ORTHO'; camera.data.ortho_scale=14.5; bpy.context.scene.camera=camera
for loc,energy,size in [((0,-8,8),2100,8),((8,-5,1),1600,6),((-6,3,5),1800,5)]:
    bpy.ops.object.light_add(type='AREA',location=loc);light=bpy.context.object;light.data.energy=energy;light.data.shape='DISK';light.data.size=size
    light.rotation_euler=(Vector((3,0,-3))-light.location).to_track_quat('-Z','Y').to_euler()
scene=bpy.context.scene;scene.render.engine='CYCLES';scene.cycles.samples=24
scene.world.color=(0.13,0.13,0.13);scene.render.resolution_x=1600;scene.render.resolution_y=1400;scene.render.resolution_percentage=100
scene.render.image_settings.file_format='PNG';scene.render.filepath=str(SOURCE/'asset-review.png')
bpy.ops.render.render(write_still=True)
print('DIGITAL_DOJO_KIT_COMPLETE',json.dumps(inventory))
