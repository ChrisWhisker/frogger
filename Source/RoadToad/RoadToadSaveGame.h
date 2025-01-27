// Copyright © 2023-2024 Chris Worcester. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RoadToadSaveGame.generated.h"

// Save data object containing all variables that need to persist between games
UCLASS(BlueprintType)
class ROADTOAD_API URoadToadSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	float SoundsVolume = 1;

	UPROPERTY(BlueprintReadOnly)
	float MusicVolume = 1;

	UPROPERTY(BlueprintReadOnly)
	int HighScore = 0;

	UPROPERTY(BlueprintReadOnly)
	int HighestLevelReached = 1;
};
