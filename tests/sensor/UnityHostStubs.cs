// HOST TEST ONLY. Minimal surfaces for production C# compilation; not Unity runtime emulation.
using System;
using System.Collections.Generic;
namespace UnityEngine
{
    [AttributeUsage(AttributeTargets.Field)] public sealed class SerializeField : Attribute { }
    [AttributeUsage(AttributeTargets.Class)] public sealed class CreateAssetMenuAttribute : Attribute
    { public string fileName, menuName; }
    [AttributeUsage(AttributeTargets.Field)] public sealed class HeaderAttribute : Attribute { public HeaderAttribute(string text) { } }
    [AttributeUsage(AttributeTargets.Field)] public sealed class RangeAttribute : Attribute { public RangeAttribute(float min, float max) { } }
    public class Object
    {
        protected static void Destroy(Object value) { }
        protected static void DontDestroyOnLoad(Object value) { }
        public static T FindObjectOfType<T>() where T : class { return null; }
    }
    public class GameObject : Object
    {
        public string name;
        public GameObject(string name = "") { this.name = name; }
        public T AddComponent<T>() where T : new() { return new T(); }
    }
    public class MonoBehaviour : Object
    {
        public GameObject gameObject = new GameObject();
        protected T GetComponent<T>() where T : class { return null; }
    }
    public class ScriptableObject : Object { public static T CreateInstance<T>() where T : new() => new T(); }
    public struct Vector2
    {
        public float x, y;
        public Vector2(float x, float y) { this.x = x; this.y = y; }
        public static Vector2 zero => new Vector2(0, 0);
        public static float Distance(Vector2 a, Vector2 b) => (float)Math.Sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
        public static implicit operator Vector2(Vector3 value) => new Vector2(value.x, value.y);
    }
    public struct Vector3
    {
        public float x, y, z;
        public Vector3(float x, float y, float z) { this.x = x; this.y = y; this.z = z; }
        public static Vector3 zero => new Vector3(0, 0, 0);
        public float magnitude => (float)Math.Sqrt(x*x+y*y+z*z);
    }
    public static class Mathf
    {
        public static float Max(float a, float b) => Math.Max(a, b);
        public static int Max(int a, int b) => Math.Max(a, b);
        public static float Min(float a, float b) => Math.Min(a, b);
        public static float Clamp01(float value) => Math.Clamp(value, 0f, 1f);
    }
    public static class Time
    {
        public static double realtimeSinceStartupAsDouble = 1000;
        public static float unscaledTime = 1000;
        public static float time = 1000;
        public static int frameCount = 1;
    }
    public static class Debug
    {
        public static void Log(object value) => Console.WriteLine(value);
        public static void LogWarning(object value) => Console.WriteLine(value);
        public static void LogError(object value) => Console.Error.WriteLine(value);
    }
    public static class Screen { public static int width = 1920; public static int height = 1080; }
    public enum KeyCode { LeftArrow, RightArrow, A, D }
    public enum TouchPhase { Began, Moved, Stationary, Ended, Canceled }
    public struct Touch { public TouchPhase phase; public Vector2 position; public int fingerId; }
    public static class Input
    {
        public static readonly HashSet<KeyCode> DownKeys = new HashSet<KeyCode>();
        public static int touchCount => 0;
        public static Vector3 mousePosition => Vector3.zero;
        public static bool GetKeyDown(KeyCode key) => DownKeys.Contains(key);
        public static bool GetMouseButtonDown(int button) => false;
        public static bool GetMouseButtonUp(int button) => false;
        public static Touch GetTouch(int index) => default;
    }
    public static class JsonUtility
    {
        public static T FromJson<T>(string json) => System.Text.Json.JsonSerializer.Deserialize<T>(json,
            new System.Text.Json.JsonSerializerOptions { IncludeFields = true });
        public static string ToJson(object value, bool prettyPrint = false) => System.Text.Json.JsonSerializer.Serialize(value,
            value.GetType(), new System.Text.Json.JsonSerializerOptions { IncludeFields = true, IgnoreReadOnlyProperties = true, WriteIndented = prettyPrint });
    }
    public class TextAsset { public string text; }
    public static class Resources { public static T Load<T>(string path) where T : class => null; }
    public static class Application
    {
        public static string persistentDataPath;
        public static string version = "SYNTHETIC_HOST_ONLY_NOT_EMPIRICAL";
        public static string unityVersion = "HOST_STUBS_NOT_UNITY";
    }
}
// Configuration/GameManager surfaces referenced by providers; no scene or lifecycle behavior.
public class GameConfig
{
    public float SensorPunchAccelerationThreshold = 18f;
    public float SensorKickAccelerationThreshold = 16f;
    public float SensorActionCooldown = 0.12f;
    public float BlockHoldDuration = 0.5f;
    public float SwipeMinDistance = 200f;
    public float SwipeMaxDuration = 0.3f;
    public float BlockMaxMovement = 10f;
    public InputSourceType ActiveInputSourceType = InputSourceType.Keyboard;
}
public class GameManager
{
    public static GameManager Instance;
    public GameState CurrentState;
}
// Logger fixture's target values are typed inputs, not a simulated scene or physical target.
public class TargetObject
{
    public string TargetId;
    public TargetType Type;
    public LaneType Lane;
    public float SpawnTime, HitWindow, MoveSpeed, ExpectedHitTime, HeavyTimeoutSeconds;
    public int MaxHits, CurrentHits;
    public bool IsTough;
}
public class HitZoneEvaluator { public float HitZoneZ = 5f; }
namespace UnityEngine.EventSystems
{
    public class EventSystem
    {
        public static EventSystem current;
        public bool PointerOverUi;
        public bool IsPointerOverGameObject(int pointerId = -1) => PointerOverUi;
    }
}
