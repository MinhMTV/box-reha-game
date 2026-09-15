"""Lighting/material refinement plus inspectable hero assembly and review cameras."""
import bpy, json, math
from pathlib import Path
from mathutils import Vector
src=Path(__file__).resolve().parent/'ReferenceRefinement'
bpy.ops.wm.open_mainfile(filepath=str(src/'ReferenceDojo.blend'))
scene=bpy.context.scene
# Long anisotropic walnut grain instead of an effectively uniform board finish.
wood=bpy.data.materials['M_DD_Wood_Dark'];nt=wood.node_tree;b=nt.nodes.get('Principled BSDF')
for node in nt.nodes:
    if node.type=='VECT_MATH':node.inputs[1].default_value=(26,.4,3)
    if node.type=='TEX_NOISE':node.inputs['Scale'].default_value=2;node.inputs['Roughness'].default_value=.72
b.inputs['Roughness'].default_value=.23;b.inputs['Coat Weight'].default_value=.2
for obj in bpy.data.objects:
    if obj.type=='MESH' and obj.name.startswith(('RiverPebble','LeafCluster')):
        for poly in obj.data.polygons:poly.use_smooth=True
# Keep ceiling dark; amber colour is supplied by fixtures, not a bright brown slab.
ceiling=bpy.data.objects.get('CeilingCoffer')
if ceiling:
    ceiling.data.materials.clear();ceiling.data.materials.append(bpy.data.materials['M_DD_MatteBlack'])
# Actual model hierarchy, not a proxy, arranged as the reference hero assembly.
with bpy.data.libraries.load(str(src/'MountedTargetKit.blend'),link=False) as (data,loaded):
    loaded.objects=list(data.objects)
for o in loaded.objects:
    if o:scene.collection.objects.link(o)
roots=[o for o in loaded.objects if o and o.parent is None]
for obj in roots:
    if obj.name.startswith('MountedHeavyTarget'):
        obj.location=(0,3.5,.882);obj.scale=(.7,.7,.7)
    elif obj.name.startswith('MountedPunchTarget'):
        obj.location=(-2.9,1.1,1.5);obj.scale=(.62,.62,.62);obj.rotation_euler[2]=-.30
        clone=obj.copy();clone.data=obj.data;scene.collection.objects.link(clone);clone.location.x=2.9;clone.rotation_euler[2]=.30
        # Deep-copy only object transforms; meshes and materials are shared between paired targets.
        def children(old,new):
            for c in old.children:
                copy=c.copy();scene.collection.objects.link(copy);copy.parent=new;children(c,copy)
        children(obj,clone)
    else:
        for c in [obj]+list(obj.children_recursive):c.hide_render=True
# Physical lateral brackets visibly meet both side supports.
for side in [-1,1]:
    a=Vector((side*3.99,1.38,1.5));b=Vector((side*2.9,1.25,1.5))
    bpy.ops.mesh.primitive_cube_add(size=1,location=(a+b)/2);arm=bpy.context.object;arm.name='ReviewSideTelescopicMount';arm.rotation_euler=(b-a).to_track_quat('Z','Y').to_euler();arm.scale=(.10,.12,(b-a).length);arm.data.materials.append(bpy.data.materials['M_DD_MetalDark'])
    bpy.ops.mesh.primitive_cube_add(size=1,location=a);plate=bpy.context.object;plate.name='ReviewSideWallPlate';plate.scale=(.07,.33,.48);plate.data.materials.append(bpy.data.materials['M_DD_MetalDark'])
scene.camera=bpy.data.objects.get('Camera');scene.cycles.samples=40;scene.render.resolution_x=1440;scene.render.resolution_y=1000
bpy.ops.wm.save_as_mainfile(filepath=str(src/'DojoAssemblyReview.blend'))
scene.render.filepath=str(src/'room-assembly-review.png');bpy.ops.render.render(write_still=True)
# QA views derive from the actual room meshes, without staging a substitute shell.
cam=scene.camera;scene.cycles.samples=12;scene.render.resolution_x=900;scene.render.resolution_y=650
views=[('corner-sw',(-3.6,-4.5,1.6),(1,2,1.5)),('corner-se',(3.6,-4.5,1.6),(-1,2,1.5)),('corner-nw',(-3.6,4.5,1.6),(1,-2,1.5)),('corner-ne',(3.6,4.5,1.6),(-1,-2,1.5)),('ceiling-up',(0,0,1),(0,0,3)),('ceiling-a',(0,-3.7,1.1),(0,1,2.8)),('ceiling-b',(0,3.7,1.1),(0,-1,2.8))]
for name,pos,target in views:
    cam.location=pos;cam.rotation_euler=(Vector(target)-cam.location).to_track_quat('-Z','Y').to_euler();cam.data.lens=10.4 if name.startswith('corner') else 6.5 if name=='ceiling-up' else 14
    scene.render.filepath=str(src/(name+'.png'));bpy.ops.render.render(write_still=True)
# Lower-room plan, hiding only the ceiling layers, projection of all actual object silhouettes.
for o in bpy.data.objects:
    if o.name.startswith(('Ceiling','SubstrateCeiling')):o.hide_render=True
cam.data.type='ORTHO';cam.data.ortho_scale=11;cam.location=(0,0,12);cam.rotation_euler=(0,0,0)
cam.rotation_euler=(Vector((0,0,0))-cam.location).to_track_quat('-Z','Y').to_euler()
scene.render.filepath=str(src/'plan-lower.png');bpy.ops.render.render(write_still=True)
print('REFERENCE_REVIEW_SUITE_COMPLETE')
