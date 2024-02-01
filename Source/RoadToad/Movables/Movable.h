// Copyright © 2023-2024 Chris Worcester. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movable.generated.h"

class UPowerUp;
class ARoadToadGameMode;

UCLASS()
class ROADTOAD_API AMovable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovable();

	// UPROPERTY()
	// UPowerUp* BubblePowerUp;
	//
	// UPROPERTY()
	// UPowerUp* SlowMoPowerUp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 125;

	virtual void SpawnPowerUp(bool Bubble);

	virtual void DespawnPowerUps();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Enabled = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Slowed = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RespawnDistance = 100;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ARoadToadGameMode> RoadToadGameMode;

	virtual void Respawn();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
