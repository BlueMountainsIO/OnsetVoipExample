// Copyright Blue Mountains GmbH. All rights reserved.


#include "VoiceExampleGameInstance.h"
#include "Misc/NetworkVersion.h"
#include "Engine/GameViewportClient.h"
#include "Engine/Console.h"

void UVoiceExampleGameInstance::Init()
{
	Super::Init();

	FNetworkVersion::GetLocalNetworkVersionOverride.BindUObject(this, &UVoiceExampleGameInstance::OnGetLocalNetworkVersionOverride);
	
	UGameViewportClient::OnViewportCreated().AddUObject(this, &UVoiceExampleGameInstance::OnViewportCreated);
}

uint32 UVoiceExampleGameInstance::OnGetLocalNetworkVersionOverride()
{
	return 2;
}

void UVoiceExampleGameInstance::OnViewportCreated()
{
#if UE_BUILD_SHIPPING
	if (GetWorld())
	{
		GetWorld()->GetGameViewport()->ViewportConsole = NewObject<UConsole>(GetWorld()->GetGameViewport(), GEngine->ConsoleClass);
	}
#endif
}
