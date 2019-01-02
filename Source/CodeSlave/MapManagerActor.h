// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileObject.h"
#include "PaperTileMapComponent.h"
#include "PaperTileSet.h"
#include "MapManagerActor.generated.h"

UCLASS()
class CODESLAVE_API AMapManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapManagerActor();

	TArray<ATileObject*> mapDataStorage;

	// Do not edit this below 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapSetting, meta = (AllowPrivateAccess = true))
		int mapSizeX;

	// Do not edit this below 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapSetting, meta = (AllowPrivateAccess = true))
		int mapSizeY;

	// the size of a base tile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapSetting, meta = (AllowPrivateAccess = true))
		int tileSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MapUtility, meta = (AllowPrivateAccess = true))
		class UPaperTileMapComponent* gridLine;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MapUtility, meta = (AllowPrivateAccess = true))
		class UPaperTileMapComponent* baseFloor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MapUtility, meta = (AllowPrivateAccess = true))
		class UPaperTileMapComponent* baseWall;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MapUtility, meta = (AllowPrivateAccess = true))
		class UPaperTileMapComponent* constructionLayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapData, meta = (AllowPrivateAccess = true))
		TMap<FString, TSubclassOf<ATileObject>> spawnableObjects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapData, meta = (AllowPrivateAccess = true))
		UPaperTileSet* baseTileSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapData, meta = (AllowPrivateAccess = true))
		TMap<FString, int> spawnableWallsAndFloors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Scene, meta = (AllowPrivateAccess = true))
		class USceneComponent* rootScene;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// get the world position of a single tile by tile index
	UFUNCTION(BlueprintCallable)
		FVector getTileWorldPositon(int x, int y);

	UFUNCTION(BlueprintCallable)
		FVector2D getTileIndexFromWorldPosition(FVector pos);

	UFUNCTION(BlueprintCallable)
		void TileMapSetUp();

	UFUNCTION(BlueprintCallable)
		void ToggleGrid(bool val) { this->gridLine->bVisible = val; };

	void clearTileMap();
	
	
};
