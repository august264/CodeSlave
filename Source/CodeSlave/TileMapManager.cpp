// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMapManager.h"

TileMapManager::TileMapManager()
{
	loadUpAllTiles();
}

TileMapManager::~TileMapManager()
{
}

void TileMapManager::loadUpAllTiles()
{
}

TArray<TArray<ATileObject*>>* TileMapManager::createMap(int32 sizeX, int32 sizeY)
{
	mapInfo.Add(TArray<ATileObject*>());
	mapInfo.Add(TArray<ATileObject*>());
	mapInfo.Add(TArray<ATileObject*>());
	mapInfo.Add(TArray<ATileObject*>());

	// add top wall

	// add border
	mapInfo[0].Add(tilesInfo["wall_top_left_corner"]);
	mapInfo[1].Add(tilesInfo["wall_horizontal_Top"]);
	mapInfo[2].Add(tilesInfo["wall_horizontal_Top"]);
	mapInfo[3].Add(tilesInfo["wall_horizontal_Top"]);

	// add top wall
	for (unsigned int i = 0; i < sizeY-2; i++)
	{
		mapInfo[0].Add(tilesInfo["Wall_top_vertical"]);
		mapInfo[1].Add(tilesInfo["Wall_mid"]);
		mapInfo[2].Add(tilesInfo["Wall_mid"]);
		mapInfo[3].Add(tilesInfo["Wall_bot"]);
	}

	// add border
	mapInfo[0].Add(tilesInfo["wall_top_right_corner"]);
	mapInfo[1].Add(tilesInfo["wall_horizontal_Top"]);
	mapInfo[2].Add(tilesInfo["wall_horizontal_Top"]);
	mapInfo[3].Add(tilesInfo["wall_horizontal_Top"]);

	// add floor
	for (unsigned int i = 4; i < sizeX+1; i++)
	{
		mapInfo.Add(TArray<ATileObject*>());
		mapInfo[i].Add(tilesInfo["Wall_top_vertical"]);
		for (unsigned int j = 0; j < sizeY; j++)
		{
			mapInfo[i].Add(tilesInfo["Floor"]);
		}
		mapInfo[i].Add(tilesInfo["Wall_top_vertical"]);
	}

	// handles the bottom wall
	mapInfo.Add(TArray<ATileObject*>());
	mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_bot_left_corner"]);
	for (unsigned int i = 0; i < sizeY; i++)
	{
		mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_horizontal_Top"]);
	}
	mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_bot_left_corner"]);

	for (unsigned int i = 0; i < 2; i++)
	{
		mapInfo.Add(TArray<ATileObject*>());
		mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_mid"]);
		for (unsigned int j = 0; j < sizeY; j++)
		{
			mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_mid"]);
		}
		mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_mid"]);

	}

	mapInfo.Add(TArray<ATileObject*>());
	mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_bot"]);
	for (unsigned int j = 0; j < sizeY; j++)
	{
		mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_bot"]);
	}
	mapInfo[mapInfo.Num() - 1].Add(tilesInfo["Wall_bot"]);




	

	return &mapInfo;
}
