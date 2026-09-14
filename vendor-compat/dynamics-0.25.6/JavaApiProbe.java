import com.riseworld.dynamics.models.domain.punch.Power;
import com.riseworld.dynamics.models.domain.punch.Power$Alpha;
public class JavaApiProbe { public static double impact(Power p) { return ((Power$Alpha)p).getImpact(); } }
