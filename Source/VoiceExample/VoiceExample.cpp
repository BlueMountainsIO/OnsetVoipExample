// Fill out your copyright notice in the Description page of Project Settings.

#include "VoiceExample.h"
#include "Debug/DebugDrawService.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Font.h"
#include "Modules/ModuleManager.h"

extern ENGINE_API float GAverageFPS;
extern ENGINE_API float GAverageMS;

class FVoiceExampleModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		FDefaultGameModuleImpl::StartupModule();

		DrawHandle = UDebugDrawService::Register(TEXT("Game"), FDebugDrawDelegate::CreateRaw(this, &FVoiceExampleModule::DrawFps));
	}

	virtual void ShutdownModule() override
	{
		if (DrawHandle.IsValid())
		{
			UDebugDrawService::Unregister(DrawHandle);
			DrawHandle.Reset();
		}

		FDefaultGameModuleImpl::ShutdownModule();
	}

private:
	void DrawFps(UCanvas* Canvas, APlayerController* PlayerController)
	{
		if (!Canvas || !Canvas->Canvas || !GEngine || IsRunningDedicatedServer())
		{
			return;
		}

		UFont* Font = FPlatformProperties::SupportsWindowedMode() ? GEngine->GetSmallFont() : GEngine->GetMediumFont();
		if (!Font)
		{
			return;
		}

		const int32 X = 4;
		int32 Y = 4;
		const int32 RowHeight = FMath::TruncToInt(Font->GetMaxCharHeight() * 1.1f);
		const FColor FpsColor = GEngine->GetFrameTimeDisplayColor(GAverageMS);

		Canvas->Canvas->DrawShadowedString(X, Y, *FString::Printf(TEXT("%5.2f FPS"), GAverageFPS), Font, FpsColor);
		Y += RowHeight;
		Canvas->Canvas->DrawShadowedString(X, Y, *FString::Printf(TEXT("%5.2f ms"), GAverageMS), Font, FpsColor);
	}

	FDelegateHandle DrawHandle;
};

IMPLEMENT_PRIMARY_GAME_MODULE(FVoiceExampleModule, VoiceExample, "VoiceExample");
