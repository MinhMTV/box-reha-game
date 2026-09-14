#if UNITY_EDITOR && UNITY_ANDROID
using System;
using UnityEditor.Android;
using UnityEngine;

/// <summary>Configures only Unity's generated Android export, preserving project templates.</summary>
public sealed class DynamicsAndroidGradleIntegration : IPostGenerateGradleAndroidProject
{
    public int callbackOrder => 10000;
    public void OnPostGenerateGradleAndroidProject(string path)
    {
        string repository = Environment.GetEnvironmentVariable("DYNAMICS_MAVEN_PATH");
        if (string.IsNullOrWhiteSpace(repository)) repository = @"C:\dynamics-sdk-main\mavenLocal";
        string mode = Environment.GetEnvironmentVariable("DYNAMICS_SDK_MODE") ?? "VENDOR-UNCHANGED";
        DynamicsGradleExportConfig.Configure(path, repository, mode);
        Debug.Log("[Dynamics] SDK build mode: " + mode);
        Debug.Log("[Dynamics] Generated Android build configured for SDK 0.25.6 / Kotlin 2.3.21. This is not a build or hardware verification result.");
    }
}
#endif
