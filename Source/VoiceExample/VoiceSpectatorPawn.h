// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "VoiceSpectatorPawn.generated.h"

/**
 * Credits go to: https://wizardcell.com/unreal/spectating-system/
 */
UCLASS()
class VOICEEXAMPLE_API AVoiceSpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()
	
public:	
	/** Move camera to next player */
	UFUNCTION(BlueprintCallable, Category = "VoiceSpectatorPawn")
	void ViewNextPlayer();

	/** Move camera to previous player */
	UFUNCTION(BlueprintCallable, Category = "VoiceSpectatorPawn")
	void ViewPrevPlayer();
};
