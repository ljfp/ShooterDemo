// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterDemoPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterDemoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}

void AShooterDemoPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromParent();
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LooseScreen = CreateWidget(this, LooseScreenClass);
		if (LooseScreen != nullptr)
		{
			LooseScreen->AddToViewport();
		}
	}
	//UE_LOG(LogTemp, Warning, TEXT("The game has finished."))

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
