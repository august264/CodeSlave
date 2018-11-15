// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Employee.h"
#include "PaperTileMapComponent.h"
#include "PaperTileSet.h"
#include "CodeSlave_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class CODESLAVE_API ACodeSlave_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	// constructor
	ACodeSlave_GameMode();

	// BeginPlay
	virtual void BeginPlay() override;

	// Tick
	virtual void Tick(float deltaSeconds) override;

private:

	// tile texture set
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map texture set", meta = (AllowPrivateAccess = true))
		UPaperTileSet* textureSet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map1", meta = (AllowPrivateAccess = true))
		UPaperTileMap* map1;
};
