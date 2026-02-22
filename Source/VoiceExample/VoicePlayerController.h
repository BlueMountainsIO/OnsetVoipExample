// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VoicePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VOICEEXAMPLE_API AVoicePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	/** Set Player to play. Should be called only on server */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetPlayerPlay();

	/** Set Player to spectate. Should be called only on server */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetPlayerSpectate();

	virtual void BeginSpectatingState() override;

	/** Replication Notification Callback */
	virtual void OnRep_Pawn() override;

};
