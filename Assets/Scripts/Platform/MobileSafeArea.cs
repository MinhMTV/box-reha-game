using UnityEngine;

/// <summary>Insets a Canvas child for display cutouts without changing the reference resolution.</summary>
public class MobileSafeArea : MonoBehaviour
{
    private Rect lastArea;
    private Vector2 lastSize;
    void OnEnable() { Refresh(); }
    void Update() { Refresh(); }
    private void Refresh()
    {
        if (Screen.width <= 0 || Screen.height <= 0) return;
        Rect area = Screen.safeArea;
        Vector2 size = new Vector2(Screen.width, Screen.height);
        if (area == lastArea && size == lastSize) return;
        lastArea = area; lastSize = size;
        RectTransform rect = GetComponent<RectTransform>();
        rect.anchorMin = new Vector2(area.xMin / size.x, area.yMin / size.y);
        rect.anchorMax = new Vector2(area.xMax / size.x, area.yMax / size.y);
        rect.offsetMin = rect.offsetMax = Vector2.zero;
    }
    public static RectTransform Create(Transform canvas)
    {
        GameObject root = new GameObject("SafeArea", typeof(RectTransform));
        root.transform.SetParent(canvas, false);
        root.AddComponent<MobileSafeArea>();
        return root.GetComponent<RectTransform>();
    }
}
