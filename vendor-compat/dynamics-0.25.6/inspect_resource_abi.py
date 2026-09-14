"""Read-only constant-pool linkage audit. Does not execute SDK code or infer semantic compatibility."""
from pathlib import Path
import argparse, io, json, struct, zipfile

def parse(data):
    f = io.BytesIO(data)
    def u(n): return int.from_bytes(f.read(n), 'big')
    assert u(4) == 0xCAFEBABE
    u(2); u(2); count=u(2); cp=[None]*count; i=1
    while i<count:
        tag=u(1)
        if tag==1: cp[i]=(tag,f.read(u(2)).decode('utf-8',errors='replace'))
        elif tag in (7,8,16,19,20): cp[i]=(tag,u(2))
        elif tag in (9,10,11,12,17,18): cp[i]=(tag,u(2),u(2))
        elif tag in (3,4): f.read(4)
        elif tag in (5,6): f.read(8); i+=1
        elif tag==15: cp[i]=(tag,u(1),u(2))
        else: raise ValueError(tag)
        i+=1
    def text(index): return cp[index][1]
    def cls(index): return text(cp[index][1]) if index else ''
    u(2); name=cls(u(2)); parent=cls(u(2)); interfaces=[cls(u(2)) for _ in range(u(2))]
    members=set()
    def attrs():
        for _ in range(u(2)): u(2); f.read(u(4))
    for kind in ('field','method'):
        for _ in range(u(2)):
            access=u(2); member=text(u(2)); descriptor=text(u(2)); members.add((kind,member,descriptor)); attrs()
    refs=[]
    for value in cp:
        if value and value[0] in (9,10,11):
            owner=cls(value[1]); nt=cp[value[2]]
            if owner.startswith('com/riseworld/launchpad/resource/'):
                refs.append((owner,'field' if value[0]==9 else 'method',text(nt[1]),text(nt[2])))
    return name,parent,interfaces,members,refs

def main():
    parser=argparse.ArgumentParser(); parser.add_argument('--sdk',default=r'C:\dynamics-sdk-main'); parser.add_argument('--output',default=str(Path(__file__).parent/'evidence/resource-linkage.json')); args=parser.parse_args()
    classes={}; references={}
    for aar in Path(args.sdk,'mavenLocal').rglob('*.aar'):
        with zipfile.ZipFile(aar) as outer, zipfile.ZipFile(io.BytesIO(outer.read('classes.jar'))) as jar:
            for item in jar.namelist():
                if not item.endswith('.class'): continue
                name,parent,interfaces,members,refs=parse(jar.read(item)); classes[name]=(parent,interfaces,members)
                if not name.startswith('com/riseworld/launchpad/resource/'):
                    for ref in refs: references.setdefault(ref,set()).add(name)
    def exists(owner,member,seen=None):
        seen=set() if seen is None else seen
        if owner in seen or owner not in classes: return False
        seen.add(owner); parent,interfaces,members=classes[owner]
        return member in members or any(exists(p,member,seen) for p in [parent]+interfaces)
    rows=[dict(owner=r[0],kind=r[1],name=r[2],descriptor=r[3],resolved=exists(r[0],r[1:]),callers=sorted(v)) for r,v in sorted(references.items())]
    result=dict(scope='Static member descriptors referenced by supplied Android AARs versus supplied resource 2.12.0. No resource 2.11.1 binary is available for behavioral comparison; no device execution.',references=len(rows),unresolved=sum(not r['resolved'] for r in rows),members=rows)
    Path(args.output).write_text(json.dumps(result,indent=2)); print(json.dumps({k:v for k,v in result.items() if k!='members'})); return int(result['unresolved']>0)
if __name__=='__main__': raise SystemExit(main())
