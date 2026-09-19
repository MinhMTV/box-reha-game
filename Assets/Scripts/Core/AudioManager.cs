using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// Lightweight procedural AudioManager for arcade feedback without external assets.
/// </summary>
public class AudioManager : MonoBehaviour
{
    public static AudioManager Instance { get; private set; }

    [SerializeField] private float masterVolume = 0.5f;

    private AudioSource oneShotSource;
    private Dictionary<string, AudioClip> clips;

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        oneShotSource = gameObject.GetComponent<AudioSource>();
        if (oneShotSource == null)
        {
            oneShotSource = gameObject.AddComponent<AudioSource>();
        }

        oneShotSource.playOnAwake = false;
        oneShotSource.spatialBlend = 0f;
        oneShotSource.loop = false;
        oneShotSource.volume = masterVolume;

        BuildClips();
    }

    public void PlayHitSound()
    {
        Play("Hit", 1f);
    }

    public void PlayKickSound()
    {
        Play("Kick", 1f);
    }

    public void PlayMissSound()
    {
        Play("Miss", 0.85f);
    }

    public void PlayComboSound()
    {
        Play("Combo", 1f);
    }

    /// <summary>
    /// v3: Sound when hitting a tough target (not destroyed yet).
    /// </summary>
    public void PlayToughHitSound()
    {
        Play("ToughHit", 1f);
    }

    /// <summary>
    /// v3: Sound when a tough target is finally destroyed.
    /// </summary>
    public void PlayToughBreakSound()
    {
        Play("ToughBreak", 1f);
    }

    private void Play(string key, float volumeScale)
    {
        if (oneShotSource == null || clips == null)
        {
            return;
        }

        AudioClip clip;
        if (!clips.TryGetValue(key, out clip) || clip == null)
        {
            return;
        }

        oneShotSource.PlayOneShot(clip, masterVolume * volumeScale * SettingsManager.SfxVolume);
    }

    private void BuildClips()
    {
        clips = new Dictionary<string, AudioClip>();
        clips["Deploy"] = CreateSweepClip("Deploy",140f,280f,.23f,.07f,.04f);
        clips["TooLight"] = CreateImpactClip("TooLight",90f,65f,.09f,.025f,.02f);
        clips["HeavyKickDamage"] = CreateImpactClip("HeavyKickDamage",56f,72f,.22f,.12f,.25f);
        clips["HeavyKickBreak"] = CreateImpactClip("HeavyKickBreak",70f,35f,.35f,.18f,.3f);
        clips["Perfect"] = CreateArpeggioClip("Perfect",new[]{660f,880f},.12f,.025f);
        clips["SessionStart"] = CreateArpeggioClip("SessionStart",new[]{220f,330f,440f},.4f,.03f);
        clips["SessionEnd"] = CreateArpeggioClip("SessionEnd",new[]{440f,330f,220f},.5f,.03f);
        clips["Hit"] = CreateImpactClip("Hit", 110f, 190f, 0.12f, 0.14f, 0.28f);
        clips["Kick"] = CreateImpactClip("Kick", 76f, 145f, 0.15f, 0.18f, 0.34f);
        clips["Miss"] = CreateSweepClip("Miss", 280f, 140f, 0.14f, 0.07f, 0.12f);
        clips["Combo"] = CreateArpeggioClip("Combo", new float[] { 440f, 554f, 659f }, 0.23f, 0.06f);
        clips["ToughHit"] = CreateImpactClip("ToughHit", 86f, 122f, 0.18f, 0.20f, 0.35f);
        clips["ToughBreak"] = CreateArpeggioClip("ToughBreak", new float[] { 120f, 180f, 280f, 420f }, 0.34f, 0.09f);
    }

    public void PlayCue(DojoAudioCue cue,bool kick=false)
    {
        switch(cue)
        {
            case DojoAudioCue.TargetDeploy:Play("Deploy",.35f);break;
            case DojoAudioCue.PunchImpact:PlayHitSound();break;
            case DojoAudioCue.KickImpact:PlayKickSound();break;
            case DojoAudioCue.TooLight:Play("TooLight",.6f);break;
            case DojoAudioCue.Perfect:Play("Perfect",.35f);break;
            case DojoAudioCue.HeavyDamage:if(kick)Play("HeavyKickDamage",1);else PlayToughHitSound();break;
            case DojoAudioCue.HeavyBreak:if(kick)Play("HeavyKickBreak",1);else PlayToughBreakSound();break;
            case DojoAudioCue.ComboTier:PlayComboSound();break;
            case DojoAudioCue.SessionStart:Play("SessionStart",.45f);break;
            case DojoAudioCue.SessionEnd:Play("SessionEnd",.45f);break;
        }
    }

    private AudioClip CreateImpactClip(string clipName, float startFrequency, float endFrequency, float duration, float noiseAmount, float overtoneAmount)
    {
        int sampleRate = 44100;
        int samples = Mathf.Max(1, Mathf.RoundToInt(sampleRate * duration));
        float[] data = new float[samples];
        float phase = 0f;
        float overtonePhase = 0f;

        for (int i = 0; i < samples; i++)
        {
            float t = i / (float)samples;
            float frequency = Mathf.Lerp(startFrequency, endFrequency, t * t);
            phase += 2f * Mathf.PI * frequency / sampleRate;
            overtonePhase += 2f * Mathf.PI * (frequency * 2.1f) / sampleRate;

            float envelope = Mathf.Exp(-7.5f * t);
            float body = Mathf.Sin(phase);
            float overtone = Mathf.Sin(overtonePhase) * overtoneAmount;
            float noise = (Random.value * 2f - 1f) * noiseAmount * (1f - t);
            data[i] = Mathf.Clamp((body + overtone + noise) * envelope, -1f, 1f);
        }

        return CreateClip(clipName, data, sampleRate);
    }

    private AudioClip CreateSweepClip(string clipName, float startFrequency, float endFrequency, float duration, float noiseAmount, float overtoneAmount)
    {
        int sampleRate = 44100;
        int samples = Mathf.Max(1, Mathf.RoundToInt(sampleRate * duration));
        float[] data = new float[samples];
        float phase = 0f;

        for (int i = 0; i < samples; i++)
        {
            float t = i / (float)samples;
            float frequency = Mathf.Lerp(startFrequency, endFrequency, t);
            phase += 2f * Mathf.PI * frequency / sampleRate;

            float envelope = Mathf.Sin(t * Mathf.PI);
            float wave = Mathf.Sin(phase) + Mathf.Sin(phase * 0.5f) * overtoneAmount;
            float noise = (Random.value * 2f - 1f) * noiseAmount;
            data[i] = Mathf.Clamp((wave + noise) * envelope * 0.75f, -1f, 1f);
        }

        return CreateClip(clipName, data, sampleRate);
    }

    private AudioClip CreateArpeggioClip(string clipName, float[] notes, float duration, float noiseAmount)
    {
        int sampleRate = 44100;
        int samples = Mathf.Max(1, Mathf.RoundToInt(sampleRate * duration));
        float[] data = new float[samples];
        int noteLength = Mathf.Max(1, samples / Mathf.Max(1, notes.Length));
        float[] phases = new float[Mathf.Max(1, notes.Length)];

        for (int i = 0; i < samples; i++)
        {
            int noteIndex = Mathf.Min(notes.Length - 1, i / noteLength);
            float frequency = notes[noteIndex];
            phases[noteIndex] += 2f * Mathf.PI * frequency / sampleRate;

            float t = i / (float)samples;
            float envelope = Mathf.Clamp01(1f - t) * 0.95f;
            float tone = Mathf.Sign(Mathf.Sin(phases[noteIndex])) * 0.35f + Mathf.Sin(phases[noteIndex]) * 0.55f;
            float noise = (Random.value * 2f - 1f) * noiseAmount * (1f - t);
            data[i] = Mathf.Clamp((tone + noise) * envelope, -1f, 1f);
        }

        return CreateClip(clipName, data, sampleRate);
    }

    private AudioClip CreateClip(string clipName, float[] data, int sampleRate)
    {
        AudioClip clip = AudioClip.Create(clipName, data.Length, 1, sampleRate, false);
        clip.SetData(data, 0);
        return clip;
    }
}
