// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LvlPaperSpriteComponent.h"
#include "TileObject.generated.h"

UCLASS()
class CODESLAVE_API ATileObject : public AActor
{
	GENERATED_BODY()
	
private:
	// indicate whether other object can be overlapped onto this tile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TileSettings, meta = (AllowPrivateAccess = true))
		bool bAllowTileOverlap;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Scene, meta = (AllowPrivateAccess = true))
		class USceneComponent* rootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Sprite, meta = (AllowPrivateAccess = true))
		class ULvlPaperSpriteComponent* sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Box, meta = (AllowPrivateAccess = true))
		class UBoxComponent* box;

public:	
	// Sets default values for this actor's properties
	ATileObject();

	FORCEINLINE ULvlPaperSpriteComponent* GetPaperSpriteComponent() { return this->sprite; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
	
};
