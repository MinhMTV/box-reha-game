using System;
using System.IO;
using UnityEngine;
public static class PlayerProfileStore
{
    private const string ProfileKey="dojo_profile_v2";
    private static IProfileRepository repository;
    public static string Error { get; private set; }
    public static IProfileRepository Repository
    {
        get
        {
            if(repository != null)return repository;
            string directory=Application.persistentDataPath;
#if UNITY_EDITOR
            if(Environment.GetEnvironmentVariable("DOJO_VISUAL_QA")=="1")directory=Path.Combine(directory,"synthetic-visual-qa");
#endif
            try
            {
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
                db.Migrate(legacy);repository=db;Error=null;
            }
            catch(Exception ex) when(ex is InvalidDataException || ex is IOException || ex is UnauthorizedAccessException)
            {
                // Refuse and preserve: never overwrite an unreadable/inaccessible database. Fall back to an
                // unsaved, in-memory profile so the rest of the game does not crash on a null/missing profile.
                Error="Profile data could not be read: "+ex.Message+" The original file is preserved; changes this session are not saved.";
                Debug.LogError("PlayerProfileStore: "+Error);
                repository=new TransientProfileRepository();
            }
            return repository;
        }
    }
    public static PlayerProfile Load()=>Repository.Get(Repository.ActiveId);
    public static void Save(PlayerProfile profile) { if(profile==null)return;Repository.Update(profile);Repository.SetActive(profile.StudyId); }
}
