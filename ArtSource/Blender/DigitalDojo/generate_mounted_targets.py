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
        modifier=obj.modifiers.new('Edge softness','BEVEL'); modifier.width=bevel; modifier.segments=2
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
def bolts(p,w,h,y):
    for x in [-w,w]:
        for z in [-h,h]:
            o=disc(p,'Fastener',.035,.018,y,'MetalDark',8);o.location.x=x;o.location.z=z

def foot(p,x,z,scale=1):
    # Raised sole silhouette with distinct heel/toes, not the old exclamation mark.
    outline=[(.035,.21),(.105,.17),(.115,.08),(.073,-.025),(.035,-.12),(.047,-.24),(.02,-.30),(-.038,-.32),(-.08,-.28),(-.073,-.18),(-.065,-.08),(-.105,.035),(-.10,.13),(-.045,.205)]
    verts=[(x+u*scale,-.295,z+v*scale) for u,v in outline]
    mesh=bpy.data.meshes.new('FootSilhouette');mesh.from_pydata(verts,[],[list(reversed(range(len(verts))))]);mesh.update()
    obj=bpy.data.objects.new('FootSilhouette',mesh);bpy.context.collection.objects.link(obj);obj.parent=p;mesh.materials.append(MATS['White'])
    for i in range(5):
        bpy.ops.mesh.primitive_uv_sphere_add(segments=10,ring_count=6,location=(x+(.09-i*.043)*scale,-.298,z+(.22-abs(i-1)*.018)*scale))
        o=bpy.context.object;o.scale=(.033*scale,.012,.043*scale);finish(o,'Toe',p,'White')

for name,heavy,kick in [('MountedPunchTarget',False,False),('MountedKickTarget',False,True),('MountedHeavyTarget',True,False),('MountedHeavyKickTarget',True,True)]:
    p=root(name);assets.append(p)
    if kick:
        w=1.65 if heavy else 1.1; h=1.35 if heavy else 1.58
        box(p,'RearHousing',(0,.08,0),(w,.3,h),'MatteBlack',.11)
        box(p,'MetalRim',(0,-.10,0),(w*.95,.16,h*.95),'MetalDark',.09)
        box(p,'ImpactPad',(0,-.21,0),(w*.85,.12,h*.83),'Padding',.08)
        bolts(p,w*.40,h*.39,-.30)
        for x in [-w*.42,w*.42]:box(p,'SideLight',(x,-.30,0),(.03,.02,h*.50),'EmissiveBlue',.008)
        for z in [-h*.38,h*.38]:box(p,'EndLight',(0,-.30,z),(w*.33,.02,.025),'EmissiveBlue',.008)
        for x in ([-.32,.32] if heavy else [0]):foot(p,x,.02,.85 if heavy else 1)
        if heavy:
            for i in range(8):box(p,'DamageSegment_%02d'%i,(-.62+i*.177,-.31,h*.44),(.12,.03,.055),'EmissiveBlue',.008)
    else:
        r=1.02 if heavy else .8
        disc(p,'RearHousing',r,.28,.1,'MatteBlack',48)
        disc(p,'MetalRim',r*.94,.13,-.1,'MetalDark',48)
        disc(p,'ImpactPad',r*.78,.09,-.20,'Padding',48)
        ring(p,'CoreRing',r*.40,.018,-.26,'EmissiveRed')
        for i in range(8):
            a=i*math.pi/4
            o=box(p,'DamageSegment_%02d'%i if heavy else 'RedLamp_%02d'%i,(math.sin(a)*r*.87,-.2,math.cos(a)*r*.87),(.25 if heavy else .17,.035,.065),'EmissiveRed',.014);o.rotation_euler[1]=a
        if not heavy:
            for i in range(4):box(p,'Knuckle',(-.105+i*.07,-.282,.03),(.062,.02,.16),'EmissiveRed',.019)
            box(p,'Thumb',(.14,-.282,-.045),(.07,.02,.12),'EmissiveRed',.024)
        bolts(p,r*.48,r*.48,-.262)
    box(p,'RearBracket',(0,.32,0),(.45,.12,.46),'MetalDark',.025)
    # Merge static material groups; keep the damage segments independently addressable.
    for mat in MATS.values():
        objects=[o for o in p.children_recursive if o.type=='MESH' and o.active_material==mat and not o.name.startswith('DamageSegment_')]
        if not objects:continue
        bpy.ops.object.select_all(action='DESELECT')
        for o in objects:o.select_set(True)
        bpy.context.view_layer.objects.active=objects[0];bpy.ops.object.join();objects[0].name='Surface_'+mat.name

p=root('MountArm');assets.append(p);box(p,'SteelArm',(0,0,0),(1,1,1),'MetalDark',.025)
p=root('MountPlate');assets.append(p);box(p,'WallPlate',(0,0,0),(1,.12,1),'MatteBlack',.045);bolts(p,.37,.37,-.075)
inventory=[]
for p in assets:
    bpy.ops.object.select_all(action='DESELECT');objects=[p]+list(p.children_recursive)
    for o in objects:o.select_set(True)
    bpy.context.view_layer.objects.active=p
    tris=0
    for o in objects:
        if o.type=='MESH':o.data.calc_loop_triangles();tris+=len(o.data.loop_triangles)
    assert tris<14000,(p.name,tris)
    inventory.append(dict(name=p.name,triangles=tris,meshes=sum(o.type=='MESH' for o in objects),front='-Y Blender',pivot='target center; mount unit center'))
    bpy.ops.export_scene.fbx(filepath=str(EXPORT/(p.name+'.fbx')),use_selection=True,object_types={'EMPTY','MESH'},add_leaf_bones=False,bake_anim=False,axis_forward='-Z',axis_up='Y',apply_unit_scale=True)
SOURCE.mkdir(parents=True,exist_ok=True)
(SOURCE/'mounted-inventory.json').write_text(json.dumps(inventory,indent=2))
bpy.ops.wm.save_as_mainfile(filepath=str(SOURCE/'MountedTargetKit.blend'))
print('MOUNTED_KIT_COMPLETE',json.dumps(inventory))
