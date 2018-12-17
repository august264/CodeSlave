// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MapManagerActor.h"
#include "GameModeBasic.generated.h"

/**
 * 
 */
UCLASS()
class CODESLAVE_API AGameModeBasic : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	// Gamemode Constructor
	AGameModeBasic();

	// Initialize the game play
	virtual void BeginPlay() override;

	// Tick function that run for every time frame;
	virtual void Tick(float DeltaTime) override;

public:

	// Some basic in-game settings that should only be accessed by developer.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameBasicSettings, meta = (ClampMin = "2"))
		int32 GameMapSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameBasicSettings, meta = (ClampMin = "2"))
		int32 GameMapSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameBasicSettings, meta = (ClampMin = "2"))
		int32 tileSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameBasicSettings, meta = (ClampMin = "2"))
		int32 tileSizeY;

	int32 getGameMapSizeX() { return this->GameMapSizeX; }
	int32 getGameMapSizeY() { return this->GameMapSizeY; }
	int32 getTileSizeX() { return this->tileSizeX; }
	int32 getTileSizeY() { return this->tileSizeY; }

private:
	// a TsubClassof map manager that will spawned into the world when begin play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InGameData, meta = (AllowPrivateAccess = true))
		TSubclassOf<AMapManagerActor> mapToSpawn;

	// a place holder to hold current map actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InGameData, meta = (AllowPrivateAccess = true))
		AMapManagerActor* currentInGameMap;

private:
	// Function blocks
	// BeginPlay, spawn the tile map actor
	void spawnMap();

public:
	UFUNCTION(BlueprintCallable)
		AMapManagerActor* getCurrentInGameMap() { return this->currentInGameMap; }
};
