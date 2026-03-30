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

    public void PlayMissSound()
    {
        Play("Miss", 0.85f);
    }

    public void PlayComboSound()
    {
        Play("Combo", 1f);
    }

    public void PlayBlockSound()
    {
        Play("Block", 0.95f);
    }

    public void PlayDodgeSound()
    {
        Play("Dodge", 0.9f);
    }

    public void PlayMenuClick()
    {
        Play("MenuClick", 0.75f);
    }

    public void PlayCountdownTick()
    {
        Play("Countdown", 0.8f);
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

        oneShotSource.PlayOneShot(clip, masterVolume * volumeScale);
    }

    private void BuildClips()
    {
        clips = new Dictionary<string, AudioClip>();
        clips["Hit"] = CreateImpactClip("Hit", 110f, 190f, 0.12f, 0.14f, 0.28f);
        clips["Miss"] = CreateSweepClip("Miss", 280f, 140f, 0.14f, 0.07f, 0.12f);
        clips["Combo"] = CreateArpeggioClip("Combo", new float[] { 440f, 554f, 659f }, 0.23f, 0.06f);
        clips["Block"] = CreateImpactClip("Block", 220f, 120f, 0.10f, 0.03f, 0.22f);
        clips["Dodge"] = CreateSweepClip("Dodge", 620f, 980f, 0.11f, 0.02f, 0.08f);
        clips["MenuClick"] = CreateSweepClip("MenuClick", 520f, 700f, 0.07f, 0.02f, 0.03f);
        clips["Countdown"] = CreateImpactClip("Countdown", 760f, 620f, 0.09f, 0.01f, 0.02f);
        clips["ToughHit"] = CreateImpactClip("ToughHit", 86f, 122f, 0.18f, 0.20f, 0.35f);
        clips["ToughBreak"] = CreateArpeggioClip("ToughBreak", new float[] { 120f, 180f, 280f, 420f }, 0.34f, 0.09f);
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
