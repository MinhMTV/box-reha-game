using UnityEngine;

public static class InputInterpreter
{
    // Development pointer input supports only Punch/Kick. Low screen input is
    // converted to Kick by the provider; all other pointer input is Punch.
    public static ActionType ClassifyAction() => ActionType.Punch;

    public static VerticalPosition GetVerticalPositionFromScreenY(float screenY)
    {
        float third=Screen.height/3f;
        if(screenY<third)return VerticalPosition.Low;
        if(screenY<third*2)return VerticalPosition.Mid;
        return VerticalPosition.High;
    }
}
