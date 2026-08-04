// Copyright Blue Mountains. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VoiceExampleGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VOICEEXAMPLE_API UVoiceExampleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	uint32 OnGetLocalNetworkVersionOverride();
	
	void OnViewportCreated();
};
