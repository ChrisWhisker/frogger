// Copyright © 2023-2024 Chris Worcester. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RoadToadGameState.generated.h"

/**
 * Contains the main game properties for the Road Toad game
 */
UCLASS()
class ROADTOAD_API ARoadToadGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	int HighScore = 0;

	// Returns the array of homes occupied by toads
	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetOccupiedHomes() const { return OccupiedHomes; }

	// Returns number of lives remaining
	UFUNCTION(BlueprintCallable)
	int GetLivesLeft() const { return LivesLeft; }

	// Returns the total game score
	UFUNCTION(BlueprintCallable)
	int GetScore() const { return Score; }

	// Returns the current level number
	UFUNCTION(BlueprintCallable)
	int GetCurrentLevel() const { return CurrentLevel; }

	// Adds this home to the array of homes occupied by toads and return the new array
	UFUNCTION(BlueprintCallable)
	TArray<AActor*> AddToOccupiedHomes(TSoftObjectPtr<AActor> EnteredHome);

	// Clears all homes
	UFUNCTION(BlueprintCallable)
	void EmptyOccupiedHomes();

	// Removes a single life from the number of lives left 
	UFUNCTION(BlueprintCallable)
	int TakeALife();

	// Resets current lives to the maximum number of lives 
	UFUNCTION(BlueprintCallable)
	int ResetLives();

	// Adds this number of points to the total game score and return the new score 
	UFUNCTION(BlueprintCallable)
	int AddPoints(const int NewPoints);

	// Resets the total game score to 0 
	UFUNCTION(BlueprintCallable)
	void ClearScore();

	// Raises the current level by 1 and returns the new level number 
	UFUNCTION(BlueprintCallable)
	int IncrementLevel();

	// Directly sets the current level number and returns it
	UFUNCTION(BlueprintCallable)
	int SetLevel(const int NewLevel);

	// Sets the current level number to 1 
	UFUNCTION(BlueprintCallable)
	void ResetToLevelOne();

	// TODO Remove
	// Temporary variable. this will be moved to the TimerSubsystem.
	// Number of seconds (counting up) on the jump timer. The toad can't jump until this reaches the max.
	UPROPERTY(BlueprintReadWrite)
	float DEPR_JumpTimerSeconds;

private:
	// Array of all homes occupied by toads
	UPROPERTY()
	TArray<AActor*> OccupiedHomes;

	// Maximum number of backup lives (how many appear on the UI)
	const int MaxLives = 2;

	// Number of backup lives remaining
	UPROPERTY()
	int LivesLeft = 2;

	// Current total game score
	UPROPERTY()
	int Score = 0;

	// The level the player is currently on
	UPROPERTY()
	int CurrentLevel = 1;
};
