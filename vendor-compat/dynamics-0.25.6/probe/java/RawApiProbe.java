import com.riseworld.dynamics.multiplatform.repository.SensorDataRepository;
import com.riseworld.dynamics.multiplatform.repository.TrainingSessionRepository;
import kotlinx.coroutines.flow.Flow;
/** Compile-only API reachability, never instantiated as a hardware experiment. */
public class RawApiProbe {
    public Flow rawAll(SensorDataRepository repository) { return repository.observeSensorDataFromAllGloves(); }
    public Flow computed(TrainingSessionRepository repository) { return repository.getActiveTrainingSessionStats(); }
    public Flow state(TrainingSessionRepository repository) { return repository.getActiveTrainingSessionTime(); }
}
