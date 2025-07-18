// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class VoiceExampleEditorTarget : TargetRules
{
	public VoiceExampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        ExtraModuleNames.AddRange( new string[] { "VoiceExample" } );
	}
}
