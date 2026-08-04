// Fill out your copyright notice in the Description page of Project Settings.


#include "VoiceSpectatorPawn.h"
#include "GameFramework/PlayerController.h"

void AVoiceSpectatorPawn::ViewNextPlayer()
{
    if (APlayerController* PC = GetController<APlayerController>())
    {
        PC->ServerViewNextPlayer();
    }
}

void AVoiceSpectatorPawn::ViewPrevPlayer()
{
    if (APlayerController* PC = GetController<APlayerController>())
    {
        PC->ServerViewPrevPlayer();
    }
}
