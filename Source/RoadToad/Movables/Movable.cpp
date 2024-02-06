// Copyright © 2023-2024 Chris Worcester. All rights reserved.


#include "Movable.h"

#include <Kismet/GameplayStatics.h>

#include "RoadToad/PowerUp.h"
#include "RoadToad/RoadToadGameMode.h"

// Sets default values
AMovable::AMovable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// BubblePowerUp = CreateDefaultSubobject<UPowerUp>(FName("Bubble PowerUp"));
	// SlowMoPowerUp = CreateDefaultSubobject<UPowerUp>(FName("SlowMo PowerUp"));
}

void AMovable::SpawnPowerUp(bool Bubble)
{
}

void AMovable::DespawnPowerUps()
{
}

// Called when the game starts or when spawned
void AMovable::BeginPlay()
{
	Super::BeginPlay();

	// Get Game Mode
	if (!RoadToadGameMode)
	{
		const TObjectPtr<AGameModeBase> GameModeBase = UGameplayStatics::GetGameMode(GetWorld());
		if (!GameModeBase)
		{
			UE_LOG(LogTemp, Error, TEXT("No game mode found."));
		}
		RoadToadGameMode = Cast<ARoadToadGameMode>(GameModeBase);
		if (!RoadToadGameMode)
		{
			UE_LOG(LogTemp, Error, TEXT("Game mode found is not of type ARoadToadGameMode."));
		}
	}
}

void AMovable::Respawn()
{
}

// Called every frame
void AMovable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Moving)
	{
		return;
	}

	const FVector Location = GetActorLocation();
	if (Location.X > RespawnDistance)
	{
		SetActorLocation(FVector(RespawnDistance * -1, Location.Y, Location.Z));
		Respawn();
	}
	else if (Location.X < RespawnDistance * -1)
	{
		SetActorLocation(FVector(RespawnDistance, Location.Y, Location.Z));
		Respawn();
	}
	else
	{
		// Just move movable at speed
		SetActorLocation(FVector((DeltaTime * Speed) + Location.X, Location.Y, Location.Z));
	}
}
