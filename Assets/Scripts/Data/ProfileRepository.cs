using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public interface IProfileRepository
{
    PlayerProfile Create(string name);
    PlayerProfile Get(string id);
    List<PlayerProfile> GetAll();
    void Update(PlayerProfile profile);
    void SetActive(string id);
    string ActiveId { get; }
    void Archive(string id);
    void Migrate(PlayerProfile legacy);
}

/// <summary>Versioned local database with atomic replacement and backup. Study IDs own all history/references.</summary>
public sealed class FileProfileRepository : IProfileRepository
{
    [Serializable] private class Database { public int version = 1; public bool legacyMigrated; public string activeId; public List<PlayerProfile> profiles = new List<PlayerProfile>(); }
    private readonly string path;
    private Database data;
    public string ActiveId => data.activeId;
    public FileProfileRepository(string directory)
    {
        path = Path.Combine(directory, "profiles-v1.json");
        if(File.Exists(path))
        {
            string json=File.ReadAllText(path);
            if(!json.Contains("\"version\"")||!json.Contains("\"profiles\""))throw new InvalidDataException("Missing profile database schema; original preserved.");
            data = JsonUtility.FromJson<Database>(json); Validate();
        }
        else data = new Database();
    }
    private void Validate()
    {
        if(data == null || data.version != 1 || data.profiles == null) throw new InvalidDataException("Profile database unreadable; original preserved.");
        var ids = new HashSet<string>();
        foreach(var p in data.profiles) if(p == null || string.IsNullOrWhiteSpace(p.StudyId) || !ids.Add(p.StudyId)) throw new InvalidDataException("Invalid or duplicate profile ID; original preserved.");
        if(data.activeId != null && !data.profiles.Exists(p=>p.StudyId == data.activeId && !p.Archived)) throw new InvalidDataException("Active profile missing or archived.");
    }
    private static PlayerProfile Copy(PlayerProfile p) => p == null ? null : JsonUtility.FromJson<PlayerProfile>(JsonUtility.ToJson(p));
    public PlayerProfile Get(string id) => Copy(data.profiles.Find(p=>p.StudyId == id));
    public List<PlayerProfile> GetAll() => data.profiles.FindAll(p=>!p.Archived).ConvertAll(Copy);
    public PlayerProfile Create(string name) { var p = new PlayerProfile { Name = name }; Update(p); return Get(p.StudyId); }
    public void Update(PlayerProfile profile)
    {
        if(profile == null || string.IsNullOrWhiteSpace(profile.StudyId)) throw new ArgumentException("Stable profile ID required");
        var p=Copy(profile);p.Name=string.IsNullOrWhiteSpace(p.Name)?"Player":p.Name.Trim();if(p.Name.Length>32)p.Name=p.Name.Substring(0,32);
        p.UpdatedUtc=DateTime.UtcNow.ToString("O"); if(string.IsNullOrEmpty(p.CreatedUtc))p.CreatedUtc=p.UpdatedUtc;
        int index=data.profiles.FindIndex(x=>x.StudyId==p.StudyId); if(index<0)data.profiles.Add(p);else data.profiles[index]=p;
        Persist();
    }
    public void SetActive(string id) { if(!data.profiles.Exists(p=>p.StudyId==id&&!p.Archived))throw new ArgumentException("Profile unavailable");data.activeId=id;Persist(); }
    public void Archive(string id)
    {
        if(data.activeId==id)throw new InvalidOperationException("Select a different profile before archiving this one.");
        var p=data.profiles.Find(x=>x.StudyId==id);if(p==null)throw new ArgumentException("Profile not found");p.Archived=true;Persist();
    }
    public void Migrate(PlayerProfile legacy)
    {
        if(data.legacyMigrated)return;
        if(legacy != null && !string.IsNullOrWhiteSpace(legacy.StudyId) && Get(legacy.StudyId)==null)Update(legacy);
        if(data.profiles.Count==0)Create("Player");
        if(data.activeId==null)data.activeId=legacy!=null&&Get(legacy.StudyId)!=null?legacy.StudyId:data.profiles[0].StudyId;
        data.legacyMigrated=true;Persist();
    }
    private void Persist()
    {
        try
        {
        Validate(); Directory.CreateDirectory(Path.GetDirectoryName(path));
        string temp=path+".tmp";
        using(var stream=new FileStream(temp,FileMode.Create,FileAccess.Write,FileShare.None))
        {byte[] bytes=System.Text.Encoding.UTF8.GetBytes(JsonUtility.ToJson(data,true));stream.Write(bytes,0,bytes.Length);stream.Flush(true);}
        if(File.Exists(path))File.Replace(temp,path,path+".bak");else File.Move(temp,path);
        }
        catch { data=File.Exists(path)?JsonUtility.FromJson<Database>(File.ReadAllText(path)):new Database();throw; }
    }
}

/// <summary>Unsaved fallback used only when the on-disk profile database refuses to load (corrupt/unreadable).
/// Never touches the original file, so the corrupt data stays available for inspection instead of being overwritten.</summary>
public sealed class TransientProfileRepository : IProfileRepository
{
    private readonly List<PlayerProfile> profiles = new List<PlayerProfile>();
    public string ActiveId { get; private set; }
    public TransientProfileRepository() { Create("Player"); }
    private static PlayerProfile Copy(PlayerProfile p) => p == null ? null : JsonUtility.FromJson<PlayerProfile>(JsonUtility.ToJson(p));
    public PlayerProfile Get(string id) => Copy(profiles.Find(p => p.StudyId == id));
    public List<PlayerProfile> GetAll() => profiles.FindAll(p => !p.Archived).ConvertAll(Copy);
    public PlayerProfile Create(string name)
    {
        var p = new PlayerProfile { Name = name, CreatedUtc = DateTime.UtcNow.ToString("O") };
        p.UpdatedUtc = p.CreatedUtc;
        profiles.Add(p);
        if (ActiveId == null) ActiveId = p.StudyId;
        return Get(p.StudyId);
    }
    public void Update(PlayerProfile profile)
    {
        if (profile == null || string.IsNullOrWhiteSpace(profile.StudyId)) throw new ArgumentException("Stable profile ID required");
        var p = Copy(profile); p.UpdatedUtc = DateTime.UtcNow.ToString("O");
        int index = profiles.FindIndex(x => x.StudyId == p.StudyId);
        if (index < 0) profiles.Add(p); else profiles[index] = p;
    }
    public void SetActive(string id) { if (!profiles.Exists(p => p.StudyId == id && !p.Archived)) throw new ArgumentException("Profile unavailable"); ActiveId = id; }
    public void Archive(string id)
    {
        if (ActiveId == id) throw new InvalidOperationException("Select a different profile before archiving this one.");
        var p = profiles.Find(x => x.StudyId == id); if (p == null) throw new ArgumentException("Profile not found"); p.Archived = true;
    }
    public void Migrate(PlayerProfile legacy) { /* Refused database; nothing to migrate into an unsaved fallback. */ }
}
