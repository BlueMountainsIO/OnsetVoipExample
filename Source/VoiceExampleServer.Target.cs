// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class VoiceExampleServerTarget : TargetRules
{
	public VoiceExampleServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        ExtraModuleNames.AddRange( new string[] { "VoiceExample" } );
		
		bUseLoggingInShipping = true;
	}
}
