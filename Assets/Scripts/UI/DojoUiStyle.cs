using UnityEngine;

/// <summary>Shared uGUI presentation tokens; gameplay and sensor state stay in their owners.</summary>
public static class DojoUiStyle
{
    public static readonly Color Ink = new Color(.045f,.049f,.053f,.96f);
    public static readonly Color Red = new Color(.72f,.12f,.085f,1);
    public static readonly Color Paper = new Color(.94f,.92f,.87f,1);
    public static readonly Color Muted = new Color(.74f,.77f,.78f,1);
    public static readonly Color Surface = new Color(.12f,.135f,.145f,1);
    public const int Display=42, H1=34, H2=25, Body=22, Caption=18, Metric=32, Button=22;
    public const float TouchHeight=64, Space=16;
    public static Font Font => Resources.Load<Font>("DigitalDojo/DojoUI") ?? Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
    public static void Style(UnityEngine.UI.Button button)
    {
        var colors=button.colors;
        colors.normalColor=Color.white;
        colors.highlightedColor=new Color(1.15f,1.15f,1.15f);
        colors.selectedColor=new Color(1.2f,1.13f,1.05f);
        colors.pressedColor=new Color(.7f,.7f,.7f);
        colors.disabledColor=new Color(.4f,.4f,.4f,.65f);
        colors.fadeDuration=.08f;button.colors=colors;
    }
}
