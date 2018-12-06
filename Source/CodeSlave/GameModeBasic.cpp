// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeBasic.h"

AGameModeBasic::AGameModeBasic() 
{
	GameMapSizeX = 20;
	GameMapSizeY = 20;
	tileSizeX = 16;
	tileSizeY = 16;
}

void AGameModeBasic::BeginPlay() 
{
	Super::BeginPlay();

	// TODO, generate map into world
}

void AGameModeBasic::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
}

void AGameModeBasic::spawnMap()
{
	FActorSpawnParameters SpawnInfo;

	FRotator myRot(0.0f, 0.0f, 0.0f);
	FVector myLoc(0.0f, 0.0f, 0.0f);


	currentInGameMap = GetWorld()->SpawnActor<AMapManagerActor>(mapToSpawn, SpawnInfo);
	currentInGameMap->SetActorLocation(myLoc);
	currentInGameMap->SetActorRotation(myRot);


}

