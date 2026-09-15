"""Inspect saved Blender bytes separately from successful generation logs."""
import bpy,json,math,hashlib
from pathlib import Path
src=Path(__file__).resolve().parent/'ReferenceRefinement'
report=[]
for filename in ['MountedTargetKit.blend','ReferenceDojo.blend','DojoAssemblyReview.blend','TargetAnimationReview.blend']:
    path=src/filename;bpy.ops.wm.open_mainfile(filepath=str(path))
    meshes=[o for o in bpy.data.objects if o.type=='MESH'];tris=0;bad=[]
    for o in meshes:
        o.data.calc_loop_triangles();tris+=len(o.data.loop_triangles)
        if not o.data.vertices or any(not math.isfinite(v) for point in o.data.vertices for v in point.co):bad.append(o.name)
    report.append({'file':filename,'sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'meshObjects':len(meshes),'trianglesAllObjectsIncludingHidden':tris,'invalidMeshes':bad,'markers':{m.name:m.frame for m in bpy.context.scene.timeline_markers},'stage':'saved source inspection; not Android performance proof'})
    assert not bad,(filename,bad)
(src/'saved-source-inspection.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
print('SAVED_SOURCE_INSPECTION_PASS',len(report))
