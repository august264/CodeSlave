// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TileObject.h"

/**
 * 
 */
class CODESLAVE_API TileMapManager
{
public:
	TileMapManager();
	~TileMapManager();

	// load all tile assets
	void loadUpAllTiles();

	// create Default Map
	TArray<TArray<ATileObject*>>* createMap(int32 sizeX, int32 sizeY);

private:
	TArray<TArray<ATileObject*>> mapInfo;

	TMap<FString, ATileObject*> tilesInfo;

};
