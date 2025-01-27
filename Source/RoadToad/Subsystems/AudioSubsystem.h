// Copyright © 2023-2024 Chris Worcester. All rights reserved.

#pragma once

#include "Misc/Optional.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AudioSubsystem.generated.h"

class AAmbientSound;

// Manages music and sound effects
UCLASS()
class ROADTOAD_API UAudioSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// ****************************** Playing ******************************

	/**
	 * Play a sound effect
	 * @param Sound sound effect
	 * @param Pitch optional
	 */
	UFUNCTION(BlueprintCallable)
	void PlaySound(USoundBase* Sound, float Pitch = 1) const;

	// ****************************** Muting ******************************

	// Set music volume to 0
	UFUNCTION(BlueprintCallable)
	void MuteMusic();

	// Set sound effects volume to 0
	UFUNCTION(BlueprintCallable)
	void MuteSounds();

	// Return music volume to its previous value before muting
	UFUNCTION(BlueprintCallable)
	void UnmuteMusic();

	// Return sound effects volume to its previous value before muting
	UFUNCTION(BlueprintCallable)
	void UnmuteSounds();

	// Mute or unmute music. Returns true if volume is not 0.
	UFUNCTION(BlueprintCallable)
	bool ToggleMusic();

	// Mute or unmute sound effects. Returns true if volume is not 0.
	UFUNCTION(BlueprintCallable)
	bool ToggleSounds();

	// ****************************** Set volume ******************************

	/**
	 * Set volume of the music track
	 * @param NewVolume
	 * @return true if volume is not 0
	 */
	UFUNCTION(BlueprintCallable)
	bool SetMusicVolume(const float NewVolume);

	// Set sound effects volume. Returns true if volume is not 0.
	UFUNCTION(BlueprintCallable)
	bool SetSoundsVolume(const float NewVolume);

	// ****************************** Getters ******************************

	// Is music volume greater than 0?
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetMusicOn() const { return MusicVolume > 0; };

	// Is sound effects volume greater than 0?
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetSoundsOn() const { return SoundsVolume > 0; };

	// Return volume level of music
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMusicVolume() const { return MusicVolume; };

	// Return volume level of sound effects
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetSoundsVolume() const { return SoundsVolume; };

private:
	UFUNCTION()
	TSoftObjectPtr<AAmbientSound> GetMusicActor();

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
