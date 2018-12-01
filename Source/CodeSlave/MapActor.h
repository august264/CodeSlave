// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileObject.h"
#include "MapActor.generated.h"


USTRUCT(BlueprintType)
struct FTile 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName tileName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<ATileObject> object;
};

USTRUCT(BlueprintType)
struct FMapData_Row
{
	GENERATED_BODY()
	// the key to access the TileObject
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> MapRow;
};

UCLASS()
class CODESLAVE_API AMapActor : public AActor
{
	GENERATED_BODY()

private:
	// Need to set for editable to overcome a UE4 bug.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = mapData, meta = (AllowPrivateAccess = true, DisplayName = "Map Data (Do not edit !! Detail in c++ file)"))
		TArray<FMapData_Row> mapData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = mapData, meta = (AllowPrivateAccess = true))
		TMap<FString, FTile> tileObjects;
	
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
	AMapActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Blueprint function, used to generate maps
	UFUNCTION(BlueprintCallable)
		void GenerateMap();

	UFUNCTION(BlueprintNativeEvent)
		void spawnTile();

	virtual void spawnTile_Implementation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Debug functions
	UFUNCTION(BlueprintCallable)
		void printCurrentMapData();

	
	
};
