"""Original reference-driven authoring room. Draft .blend; no runtime export."""
from pathlib import Path
exec((Path(__file__).parent/'generate_dojo.py').read_text(encoding='utf-8').split('assets=[]')[0])
import random
random.seed(15)
SOURCE=SOURCE/'ReferenceRefinement';SOURCE.mkdir(parents=True,exist_ok=True)
p=root('ReferenceDojo')
# Continuous 8 x 10 x 3 m shell. Fixed-camera training room has no traversable arrival.
box(p,'SubstrateFloor',(0,0,-.10),(8.4,10.4,.2),'Concrete',.01)
box(p,'SubstrateCeiling',(0,0,3.10),(8.4,10.4,.2),'MatteBlack',.01)
for x in [-4.1,4.1]:box(p,'SubstrateSide',(x,0,1.5),(.2,10.4,3.2),'Concrete',.01)
for y in [-5.1,5.1]:box(p,'SubstrateEnd',(0,y,1.5),(8.4,.2,3.2),'Concrete',.01)
# Material microstructure remains in the .blend; baking required before Unity export.
for key in ['Wood_Dark','Padding','Concrete','MatteBlack','MetalDark']:
    mat=MATS[key];nt=mat.node_tree;b=nt.nodes.get('Principled BSDF')
    coord=nt.nodes.new('ShaderNodeTexCoord');mapping=nt.nodes.new('ShaderNodeVectorMath');mapping.operation='MULTIPLY';mapping.inputs[1].default_value=(180,3,4) if key=='Wood_Dark' else (60,60,60)
    nt.links.new(coord.outputs['Generated'],mapping.inputs[0]);noise=nt.nodes.new('ShaderNodeTexNoise');noise.inputs['Scale'].default_value=3;noise.inputs['Detail'].default_value=3;nt.links.new(mapping.outputs['Vector'],noise.inputs['Vector'])
    ramp=nt.nodes.new('ShaderNodeValToRGB')
    dark=(.022,.008,.003,1) if key=='Wood_Dark' else (.012,.014,.016,1)
    light=(.13,.05,.016,1) if key=='Wood_Dark' else (.06,.065,.07,1)
    ramp.color_ramp.elements[0].color=dark;ramp.color_ramp.elements[1].color=light
    nt.links.new(noise.outputs['Fac'],ramp.inputs[0]);nt.links.new(ramp.outputs['Color'],b.inputs['Base Color'])
    bump=nt.nodes.new('ShaderNodeBump');bump.inputs['Strength'].default_value=.18;bump.inputs['Distance'].default_value=.007;nt.links.new(noise.outputs['Fac'],bump.inputs['Height']);nt.links.new(bump.outputs['Normal'],b.inputs['Normal'])
    b.inputs['Roughness'].default_value=.30 if key=='Wood_Dark' else .65
MATS['WarmLight'].node_tree.nodes.get('Principled BSDF').inputs['Emission Strength'].default_value=2
for i in range(32):
    for j in range(5):
        box(p,'WalnutPlank',(-3.875+i*.25,-4+j*2,.018),(.244,1.99,.036),'Wood_Dark',.004)
# Modules authored locally with front -Y, transformed to each support plane.
def bay(name,width,slat=False):
    q=root(name);q.parent=p
    box(q,'BayBacking',(0,.07,1.48),(width,.12,2.94),'MatteBlack',.02)
    if slat:
        n=int(width/.10)
        for i in range(n):box(q,'WalnutSlat',(-width/2+.06+i*(width-.12)/max(1,n-1),-.025,1.5),(.047,.15,2.72),'Wood_Dark',.008)
        for z in [.13,2.88]:box(q,'SlatGrazingDiffuser',(0,-.035,z),(width-.10,.12,.025),'WarmLight',.005)
    else:
        for z in [.57,1.49,2.41]:box(q,'PaddedPanel',(0,-.025,z),(width-.09,.10,.88),'Padding',.025)
        for z in [.10,2.90]:box(q,'RecessedLight',(0,-.08,z),(width-.12,.025,.018),'WarmLight',.003)
    for xx in [-width/2,width/2]:box(q,'BayFrame',(xx,0,1.5),(.035,.18,3),'MetalDark',.006)
    return q
for side in [-1,1]:
    for i in range(8):
        q=bay('SideBay',1.25,i%3==0);q.location=(side*3.99,-4.375+i*1.25,0);q.rotation_euler[2]=-side*math.pi/2
for x,width,slat in [(-3.4,1.2,False),(-2.2,1.2,True),(0,3.2,False),(2.2,1.2,True),(3.4,1.2,False)]:
    q=bay('RearBay',width,slat);q.location=(x,4.99,0)
# Real fabric surfaces, rails and typography.
fontpaths=[Path('C:/Windows/Fonts/msyh.ttc'),Path('C:/Windows/Fonts/YuGothR.ttc'),Path('C:/Windows/Fonts/meiryo.ttc')]
cjk=next((bpy.data.fonts.load(str(f)) for f in fontpaths if f.exists()),None)
def textmesh(parent,body,x,y,z,size,font=None):
    curve=bpy.data.curves.new('BannerTypography','FONT');curve.body=body;curve.align_x='CENTER';curve.size=size;curve.space_line=1.4
    if font:curve.font=font
    o=bpy.data.objects.new('BannerTypography',curve);bpy.context.collection.objects.link(o);o.parent=parent;o.location=(x,y,z);o.rotation_euler=(math.pi/2,0,0);curve.materials.append(MATS['White'])
    bpy.context.view_layer.objects.active=o;o.select_set(True);bpy.ops.object.convert(target='MESH');o.select_set(False)
def banner(name,body,width=1.25):
    q=root(name);q.parent=p
    # Dense enough for visible cloth sag; not a flat poster.
    vs=[];fs=[];nx=18;nz=24
    for iz in range(nz+1):
        for ix in range(nx+1):
            x=(ix/nx-.5)*width;z=.25+iz/nz*2.35;y=-.10-.018*math.sin(ix/nx*math.pi*5)*(1-iz/nz)-.016*math.sin(iz/nz*math.pi)
            vs.append((x,y,z))
    for iz in range(nz):
        for ix in range(nx):a=iz*(nx+1)+ix;fs.append((a,a+1,a+nx+2,a+nx+1))
    mesh=bpy.data.meshes.new('Fabric');mesh.from_pydata(vs,[],fs);mesh.materials.append(MATS['MatteBlack']);o=bpy.data.objects.new('HangingFabric',mesh);bpy.context.collection.objects.link(o);o.parent=q
    for z in [.25,2.61]:box(q,'BannerRod',(0,-.08,z),(width+.12,.055,.055),'MetalDark',.015)
    if body=='DOJO':
        textmesh(q,'道' if cjk else 'DOJO',0,-.135,1.70,.73,cjk);textmesh(q,'D I S C I P L I N E\n\nB U I L D S\n\nF R E E D O M',0,-.135,.78,.075)
    else:textmesh(q,body,0,-.135,1.90,.105)
    box(q,'BannerAccent',(0,-.14,.54),(.24,.01,.013),'RedAccent',.002)
    return q
q=banner('RearDojoBanner','DOJO',1.85);q.location=(0,4.82,0)
for side,body in [(-1,'PUNCH\nSHARPER\n\nMOVE\nBETTER\n\nBE\nSTRONGER'),(1,'KICK\nDEEPER\n\nTRAIN\nCLEANER\n\nLEVEL\nHIGHER')]:
    q=banner('SideBanner',body,.91);q.location=(side*3.82,.62,0);q.rotation_euler[2]=-side*math.pi/2
# Ceiling coffer with the broad underside exposed, warm inset perimeter.
box(p,'CeilingCoffer',(0,0,2.98),(6.8,8.6,.08),'Padding',.02)
for x in [-3.5,3.5]:
    box(p,'CeilingLongBeam',(x,0,2.91),(.14,9.0,.18),'MetalDark',.018)
    box(p,'CeilingWarmEdge',(x*.972,0,2.927),(.022,8.70,.018),'WarmLight',.004)
for y in [-4.5,4.5]:
    box(p,'CeilingCrossBeam',(0,y,2.91),(7.14,.14,.18),'MetalDark',.018)
    box(p,'CeilingWarmEdge',(0,y*.97,2.927),(6.82,.022,.018),'WarmLight',.004)
# Secondary fixtures and practical storage from the expanded reference set.
for yy in [-2.5,0,2.5]:
    box(p,'CeilingCrossRib',(0,yy,2.91),(6.8,.11,.14),'MetalDark',.015)
    box(p,'CeilingDownlight',(0,yy,2.825),(.20,.20,.015),'WarmLight',.004)
for side in [-1,1]:
    for yy in [-3.1,1.9]:
        box(p,'SconceMount',(side*3.85,yy,1.55),(.12,.16,.72),'MetalDark',.02)
        box(p,'SconceDiffuser',(side*3.77,yy,1.55),(.025,.065,.64),'WarmLight',.008)
    # Behind the target movement reserve, against the side wall.
    box(p,'TrainingBenchSeat',(side*3.33,-3.7,.43),(.68,1.7,.08),'Wood_Dark',.015)
    for yy in [-4.4,-3.0]:box(p,'BenchSteelLeg',(side*3.33,yy,.22),(.66,.10,.44),'MetalDark',.015)
    box(p,'BenchUnderglow',(side*3.0,-3.7,.14),(.012,1.4,.025),'WarmLight',.004)
    box(p,'EquipmentChest',(side*3.35,2.3,.29),(.68,.70,.58),'MatteBlack',.035)
    box(p,'ChestLid',(side*3.35,2.3,.60),(.70,.72,.05),'Wood_Dark',.01)
    box(p,'ChestHandle',(side*2.995,2.3,.43),(.025,.20,.035),'MetalDark',.007)
# Pebble troughs and branching bonsai, confined outside the playable envelope.
def stone(parent,loc,scale):
    bpy.ops.mesh.primitive_ico_sphere_add(subdivisions=1,radius=1,location=loc);o=bpy.context.object;o.scale=scale;finish(o,'RiverPebble',parent,'White')
for side in [-1,1]:
    box(p,'StoneTrough',(side*3.78,0,.05),(.40,9.8,.10),'Concrete',.008)
    for i in range(180):stone(p,(side*3.78+random.uniform(-.14,.14),random.uniform(-4.85,4.85),.12),(random.uniform(.025,.065),random.uniform(.035,.07),random.uniform(.025,.04)))
leaf=bpy.data.materials.new('M_DD_Leaves');leaf.diffuse_color=(.075,.115,.012,1);leaf.use_nodes=True;leaf.node_tree.nodes.get('Principled BSDF').inputs['Base Color'].default_value=leaf.diffuse_color;MATS['Leaves']=leaf
for side in [-1,1]:
    for yy in [-2.4,3.65]:
        q=root('BonsaiPlanter');q.parent=p;q.location=(side*3.38,yy,0)
        box(q,'Planter',(0,0,.23),(.66,.64,.46),'Concrete',.025)
        box(q,'Soil',(0,0,.468),(.58,.56,.015),'MatteBlack',.002)
        box(q,'PlanterBaseLight',(0,-.321,.065),(.58,.014,.025),'WarmLight',.004)
        for i in range(20):stone(q,(random.uniform(-.26,.26),random.uniform(-.25,.25),.49),(.04,.04,.025))
        for j in range(9):
            start=Vector((0,0,.47+j*.036));end=Vector((math.cos(j*2.4)*(.17+j*.018),math.sin(j*2.4)*.18,.82+j*.025));mid=(start+end)/2
            bpy.ops.mesh.primitive_cone_add(vertices=7,radius1=.026,radius2=.009,depth=(end-start).length,location=mid);o=bpy.context.object;o.rotation_euler=(end-start).to_track_quat('Z','Y').to_euler();finish(o,'BonsaiBranch',q,'Wood_Dark')
            for k in range(18):
                v=end+Vector((random.uniform(-.13,.13),random.uniform(-.10,.10),random.uniform(-.05,.08)))
                bpy.ops.mesh.primitive_ico_sphere_add(subdivisions=1,radius=1,location=v);o=bpy.context.object;o.scale=(.035,.018,.010);finish(o,'LeafCluster',q,'Leaves')
# One fixture manifest controls this preview; later export must consume it too.
fixtures=[]
def area(name,pos,target,power,size,color):
    bpy.ops.object.light_add(type='AREA',location=pos);o=bpy.context.object;o.name=name;o.data.energy=power;o.data.shape='DISK';o.data.size=size;o.data.color=color;o.rotation_euler=(Vector(target)-o.location).to_track_quat('-Z','Y').to_euler();fixtures.append(dict(name=name,position=pos,target=target,watts=power,size=size,color=color))
for side in [-1,1]:
    for yy in [-3.8,0,3.8]:area('WarmWallWash',(side*3.7,yy,.18),(side*3.96,yy,1.7),75,.7,(1,.47,.16))
for x in [-2.2,2.2]:area('RearSlatWash',(x,4.60,.17),(x,4.95,1.5),65,.7,(1,.47,.16))
area('CeilingFill',(0,-.5,2.82),(0,0,0),95,5,(1,.74,.48))
area('CameraFill',(0,-4.7,2.6),(0,3,1.4),35,4,(.72,.82,1))
(SOURCE/'fixtures.json').write_text(json.dumps(fixtures,indent=2),encoding='utf-8')
scene=bpy.context.scene;scene.render.engine='CYCLES';scene.cycles.samples=32;scene.cycles.use_denoising=True;scene.world.color=(.025,.025,.025);scene.render.resolution_x=1440;scene.render.resolution_y=1000;scene.render.resolution_percentage=100
bpy.ops.object.camera_add(location=(0,-4.65,1.5));cam=bpy.context.object;cam.rotation_euler=(Vector((0,3.0,1.5))-cam.location).to_track_quat('-Z','Y').to_euler();cam.data.lens=21;scene.camera=cam
bpy.ops.wm.save_as_mainfile(filepath=str(SOURCE/'ReferenceDojo.blend'))
scene.render.filepath=str(SOURCE/'room-review.png');bpy.ops.render.render(write_still=True)
tris=sum(len(o.data.polygons)*2 for o in p.children_recursive if o.type=='MESH')
(SOURCE/'room-inventory.json').write_text(json.dumps(dict(approxTriangles=tris,objects=len(p.children_recursive),dimensions=[8,10,3],stage='authoring-review',textures='procedural; unbaked; not Unity-ready',cjkFontAvailable=cjk is not None),indent=2),encoding='utf-8')
print('REFERENCE_ROOM_SAVED',tris)
