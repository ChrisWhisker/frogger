// Copyright © 2023 Chris Worcester. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RootWidget.generated.h"

class URoadToadHUD;

// The main full-screen widget that contains
UCLASS()
class FROGGER_API URootWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowPauseMenu();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HidePauseMenu();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowHUD();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HideHUD();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintPure)
	URoadToadHUD* GetHUD() const;
};
