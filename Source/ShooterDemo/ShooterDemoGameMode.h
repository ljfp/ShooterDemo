// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterDemoGameMode.generated.h"

UCLASS(minimalapi)
class AShooterDemoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShooterDemoGameMode();
	virtual void PawnKilled(APawn* PawnKilled);
};



