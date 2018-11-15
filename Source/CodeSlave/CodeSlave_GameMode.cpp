// Fill out your copyright notice in the Description page of Project Settings.

#include "ConstructorHelpers.h"
#include "CodeSlave_GameMode.h"

ACodeSlave_GameMode::ACodeSlave_GameMode() 
{
	static ConstructorHelpers::FObjectFinder<UPaperTileSet> tileSetObj(TEXT("PaperTileSet'/Game/TileMap/NewPaperTileSet.NewPaperTileSet'"));
	textureSet = tileSetObj.Object;
}

void ACodeSlave_GameMode::BeginPlay()
{
}

void ACodeSlave_GameMode::Tick(float deltaSeconds)
{
}
