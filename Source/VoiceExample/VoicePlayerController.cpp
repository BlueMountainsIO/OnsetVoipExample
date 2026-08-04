// Fill out your copyright notice in the Description page of Project Settings.


#include "VoicePlayerController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/GameModeBase.h"

#if PLATFORM_IOS
#import <AVFoundation/AVFoundation.h>
#endif

void AVoicePlayerController::BeginPlay()
{
    Super::BeginPlay();

#if PLATFORM_IOS
    // UE does not trigger the iOS microphone permission prompt on its own. Having
    // NSMicrophoneUsageDescription in the plist is required but not enough, we still
    // need to call requestRecordPermission explicitly or AVAudioSession will silently
    // deny recording and voice capture will never initialize.
    if (!IsRunningDedicatedServer() && IsLocalController())
    {
        AVAudioSession* Session = [AVAudioSession sharedInstance];
        [Session requestRecordPermission:^(BOOL granted) {
            UE_LOG(LogTemp, Log, TEXT("Microphone permission %s"), granted ? TEXT("granted") : TEXT("denied"));
        }];
    }
#endif
}

void AVoicePlayerController::SetPlayerPlay()
{
    // Only proceed if we're on the server
    if (!HasAuthority())
    {
        return;
    }

    // Update the state on server
    PlayerState->SetIsSpectator(false);
    ChangeState(NAME_Playing);

    bPlayerIsWaiting = false;

    if (GetPawn() == nullptr)
    {
        if (UWorld* World = GetWorld())
        {
            if (AGameModeBase* GM = World->GetAuthGameMode())
            {
                GM->RestartPlayer(this);
            }
        }
    }

    // Push the state update to the client
    ClientGotoState(NAME_Playing);

    // Update the HUD to remove the spectator screen
    //ClientHUDStateChanged(EHUDState::Playing);
    //ServerViewSelf();
}

void AVoicePlayerController::SetPlayerSpectate()
{
    // Only proceed if we're on the server
    if (!HasAuthority())
    {
        return;
    }

    // Update the state on server
    PlayerState->SetIsSpectator(true);
    ChangeState(NAME_Spectating);

    bPlayerIsWaiting = true;

    // Push the state update to the client
    ClientGotoState(NAME_Spectating);

    // Update the HUD to add the spectator screen
    //ClientHUDStateChanged(EHUDState::Spectating);
}

void AVoicePlayerController::BeginSpectatingState()
{
    if (PlayerCameraManager)
    {
        SetSpawnLocation(PlayerCameraManager->GetCameraLocation());
    }

    Super::BeginSpectatingState();
}

void AVoicePlayerController::OnRep_Pawn()
{
    Super::OnRep_Pawn();

    if (IsInState(NAME_Spectating))
    {
        ServerViewNextPlayer();
    }
}

