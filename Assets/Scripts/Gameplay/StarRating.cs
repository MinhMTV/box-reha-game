using UnityEngine;

/// <summary>
/// Star rating system based on accuracy.
/// 1 star: complete the level (any score)
/// 2 stars: accuracy >= 70%
/// 3 stars: accuracy >= 90%
/// </summary>
public static class StarRating
{
    private const float TwoStarThreshold = 0.7f;
    private const float ThreeStarThreshold = 0.9f;

    public static int CalculateStars(float accuracy)
    {
        if (accuracy >= ThreeStarThreshold) return 3;
        if (accuracy >= TwoStarThreshold) return 2;
        return 1;
    }

    public static string GetStarDisplay(int stars)
    {
        switch (stars)
        {
            case 3: return "★★★";
            case 2: return "★★☆";
            default: return "★☆☆";
        }
    }

    public static Color GetStarColor(int stars)
    {
        switch (stars)
        {
            case 3: return Color.yellow;
            case 2: return new Color(1f, 0.8f, 0.2f); // gold
            default: return new Color(0.6f, 0.6f, 0.6f); // gray
        }
    }
}
