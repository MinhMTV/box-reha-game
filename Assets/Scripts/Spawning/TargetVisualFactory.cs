using System;
using UnityEngine;

/// <summary>Small seam for editor/runtime fallback visuals when authored prefabs are unavailable.</summary>
internal static class TargetVisualFactory
{
    public static void BuildFallback(Transform parent, TargetType type, Action<Transform> buildKick, Action<Transform, Color, bool> buildDisc)
    {
        if (type == TargetType.Kick || type == TargetType.ToughKick)
        {
            buildKick(parent);
            return;
        }

        buildDisc(parent, GameVisualPalette.GetTargetColor(type), type == TargetType.ToughPunch);
    }
}
