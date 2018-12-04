// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperTileMapComponent.h"
#include "TileMapActor.generated.h"


USTRUCT(BlueprintType, Blueprintable)
struct FMapData_Row
{
	GENERATED_BODY()
		// the key to access the TileObject
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> MapRow;
};


UCLASS()
class CODESLAVE_API ATileMapActor : public AActor
{
	GENERATED_BODY()
	
private:
	// Need to set for editable to overcome a UE4 bug.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = mapData, meta = (AllowPrivateAccess = true, DisplayName = "Map Data (Do not edit !! Detail in c++ file)"))
		TArray<FMapData_Row> mapStringData;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MapData, meta = (AllowPrivateAccess = true))
		UPaperTileMapComponent* mapData;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Scene, meta = (AllowPrivateAccess = true))
		USceneComponent* rootScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapData, meta = (AllowPrivateAccess = true))
		UPaperTileSet* tileSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapData, meta = (AllowPrivateAccess = true))
		TMap<FString, int> tileSetIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = mapData, meta = (AllowPrivateAccess = true))
		float baseTileSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = mapData, meta = (AllowPrivateAccess = true))
		float baseTileSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = mapData, meta = (AllowPrivateAccess = true))
		int mapSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = mapData, meta = (AllowPrivateAccess = true))
		int mapSizeY;



public:	
	// Sets default values for this actor's properties
	ATileMapActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void GenerateBaseMap();
	
	
};
