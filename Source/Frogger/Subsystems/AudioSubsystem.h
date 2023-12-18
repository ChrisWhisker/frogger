// Copyright © 2023 Chris Worcester. All rights reserved.

#pragma once

#include "Misc/Optional.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AudioSubsystem.generated.h"

class AAmbientSound;

/**
 * Manages music and sound effects
 */
UCLASS()
class FROGGER_API UAudioSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Play a sound effect
	UFUNCTION(BlueprintCallable)
	void PlaySound(USoundBase* Sound, float Pitch = 1) const;

	// Set music volume to 0
	UFUNCTION(BlueprintCallable)
	void MuteMusic();

	// Return music volume to its previous value before muting
	UFUNCTION(BlueprintCallable)
	void UnmuteMusic();

	// Mute or unmute music. Returns true if volume is not 0.
	UFUNCTION(BlueprintCallable)
	bool ToggleMusic();

	// Set music volume. Returns true if volume is not 0.
	UFUNCTION(BlueprintCallable)
	bool SetMusicVolume(const float NewVolume);

	// Set sound effects volume to 0
	UFUNCTION(BlueprintCallable)
	void MuteSounds();

	// Return sound effects volume to its previous value before muting
	UFUNCTION(BlueprintCallable)
	void UnmuteSounds();

	// Mute or unmute sound effects. Returns true if volume is not 0.
	UFUNCTION(BlueprintCallable)
	bool ToggleSounds();

	// Set sound effects volume. Returns true if volume is not 0.
	UFUNCTION(BlueprintCallable)
	bool SetSoundsVolume(const float NewVolume);

	// Is music volume > 0 ?
	UFUNCTION(BlueprintCallable)
	bool GetMusicOn() const { return MusicVolume > 0; };

	// Is sound effects volume > 0 ?
	UFUNCTION(BlueprintCallable)
	bool GetSoundsOn() const { return SoundsVolume > 0; };

	// Return volume level of music
	UFUNCTION(BlueprintCallable)
	float GetMusicVolume() const { return MusicVolume; };

	// Return volume level of sound effects
	UFUNCTION(BlueprintCallable)
	float GetSoundsVolume() const { return SoundsVolume; };

private:
	UFUNCTION()
	AAmbientSound* GetMusicActor();

	TOptional<AAmbientSound*> MusicActor;

	// Maximum music volume. 1 = same volume as sounds.
	const float BASE_MUSIC_VOLUME_MULTIPLIER = 0.5f;

	UFUNCTION()
	void UpdateMusicComponentVolume();

	UPROPERTY()
	float MusicVolume = 1.0f;

	UPROPERTY()
	float MusicVolumeIfOn = 1.0f;

	UPROPERTY()
	float SoundsVolume = 1.0f;

	UPROPERTY()
	float SoundsVolumeIfOn = 1.0f;
};
