using System;
using System.IO;
using UnityEngine;
public static class PlayerProfileStore
{
    private const string ProfileKey="dojo_profile_v2";
    private static IProfileRepository repository;
    public static IProfileRepository Repository
    {
        get
        {
            if(repository != null)return repository;
            string directory=Application.persistentDataPath;
#if UNITY_EDITOR
            if(Environment.GetEnvironmentVariable("DOJO_VISUAL_QA")=="1")directory=Path.Combine(directory,"synthetic-visual-qa");
#endif
            var db=new FileProfileRepository(directory);
            PlayerProfile legacy=null;
#if UNITY_EDITOR
            if(Environment.GetEnvironmentVariable("DOJO_VISUAL_QA")=="1")legacy=new PlayerProfile {Name="QA preview",StudyId="synthetic-visual-qa"};
            else
#endif
            {
                string json=PlayerPrefs.GetString(ProfileKey,"");
                if(!string.IsNullOrWhiteSpace(json))
                {
                    legacy=JsonUtility.FromJson<PlayerProfile>(json);
                    if(legacy==null || string.IsNullOrWhiteSpace(legacy.StudyId))throw new InvalidDataException("Legacy profile unreadable; original preserved.");
                }
            }
            db.Migrate(legacy);repository=db;return repository;
        }
    }
    public static PlayerProfile Load()=>Repository.Get(Repository.ActiveId);
    public static void Save(PlayerProfile profile) { if(profile==null)return;Repository.Update(profile);Repository.SetActive(profile.StudyId); }
}
