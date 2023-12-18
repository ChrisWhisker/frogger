// Copyright © 2023 Chris Worcester. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RoadToadHUD.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate_NoParam);

UENUM(BlueprintType)
enum class ECauseOfDeath : uint8
{
	Car		UMETA(DisplayName="Car"),
	Water	UMETA(DisplayName="Water"),
	Timer	UMETA(DisplayName="Timer"),
};

/**
 * 
 */
UCLASS(Blueprintable)
class FROGGER_API URoadToadHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	// ****************************** Delegates ******************************

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FDelegate_NoParam RetryReady;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FDelegate_NoParam NextLevelReady;

	// ****************************** Full UI changes ******************************

	/**
	 * Reset all UI elements to their default at the start of the game
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetUI();

	// ****************************** Bottom panel ******************************

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HideBottomPanel();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowBottomPanel();

	// ****************************** Timers ******************************

	/**
	 * Update the progress bar representing the life countdown timer
	 * @param NewProgress Amount to fill the progress bar (between 0 and 1)
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateLifeTimer(float NewProgress);

	/**
	 * Update the progress bar representing the jump timer
	 * @param NewProgress Amount to fill the progress bar (between 0 and 1)
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateJumpTimer(float NewProgress);

	// ****************************** Gameplay Stats ******************************

	/**
	 * Update the score text
	 * @param NewScore New score to display
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateScore(int NewScore);

	/**
	 * Update number of lives to be shown as remaining
	 * @param NewLivesLeft  New number of lives
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateLivesLeft(int NewLivesLeft);

	// ****************************** Death UI ******************************

	/**
	 * Show the UI that appears when a toad has been killed
	 * @param DeathCause Reason for the
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowDeathUI(ECauseOfDeath DeathCause);

	/**
	 * Hide the UI that appears when a toad has been killed
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HideDeathUI();

	// ****************************** Game Over ******************************

	/**
	 * Show the UI that appears when the final toad has been killed
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowGameOver();

	/**
	 * Hide the Game Over UI
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HideGameOver();

	// ****************************** Level Progression ******************************

	/**
	 * Show the UI that appears when the level has been successfully beaten
	 * @param CompleteLevel The level number that was just completed
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowLevelComplete(int CompleteLevel);

	/**
	 * Update the level number on screen
	 * @param NewLevel New level number to display
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateLevelNumber(int NewLevel);
};
