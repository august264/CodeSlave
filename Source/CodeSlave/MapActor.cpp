// Fill out your copyright notice in the Description page of Project Settings.

#include "MapActor.h"
#include "Engine.h"


// Sets default values
AMapActor::AMapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
//	mapData = TArray<FMapData_Row>();
	baseTileSizeX = 0;
	baseTileSizeY = 0;
	mapSizeX = 0;
	mapSizeY = 0;
}

// Called when the game starts or when spawned
void AMapActor::BeginPlay()
{
	Super::BeginPlay();
	
}

//void AMapActor::GenerateMap()
//{
//	mapData.Empty();
//	if (mapSizeX > 0 && mapSizeY > 0)
//	{
//		for (int i = 0; i < mapSizeX + 5; i++)
//		{
//
//			mapData.Add(FMapData_Row());
//			//UE_LOG(LogTemp, Log, TEXT("x: %d"), mapData.Num());
//			for (int j = 0; j < mapSizeY + 2; j++)
//			{
//				// Do not compress the IF statement by simply combine two statement with OR. the statements are not exclusive, the order of the excution is critial. 
//				FString val;
//				if (i == 0 && j == 0)
//				{
//					val = "TOP_LEFT_CORNER";
//				}
//				else if (i == 0 && j == mapSizeY + 1)
//				{
//					val = "TOP_RIGHT_CORNER";
//				}
//				else if (i == 0)
//				{
//					val = "HORIZONTAL";
//				}
//				else if (i >= 1 && i <= 2 && (j == 0 || j == mapSizeY + 1))
//				{
//					val = "VERTICAL";
//				}
//				else if (i >= i && i <= 2)
//				{
//					val = "MID";
//				}
//				else if (i == 3 && (j == 0 || j == mapSizeY + 1))
//				{
//					val = "VERTICAL";
//				}
//				else if (i == 3)
//				{
//					val = "BOT";
//				}
//				else if (i == mapSizeX + 4 - 3 && j == 0)
//				{
//					val = "BOT_LEFT_CORNER";
//				}
//				else if (i == mapSizeX + 4 - 3 && j == mapSizeY + 1)
//				{
//					val = "BOT_RIGHT_CORNER";
//				}
//				else if (i == mapSizeX + 4 - 3)
//				{
//					val = "HORIZONTAL";
//				}
//				else if (i >= mapSizeX + 4 - 2 && i <= mapSizeX + 4 - 1)
//				{
//					val = "MID";
//				}
//				else if (i == mapSizeX + 4)
//				{
//					val = "BOT";
//				}
//				else if (j == 0 || j == mapSizeY + 1)
//				{	
//					val = "VERTICAL";
//				}
//				else
//				{
//					val = "FLOOR";
//				}
//
//				mapData[i].MapRow.Add(val);
//			}
//		}
//	}
//}

void AMapActor::spawnTile_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Spawn Tile Actor from blueprint"));

}

// Called every frame
void AMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AMapActor::printCurrentMapData()
//{
//	//UE_LOG(LogTemp, Log, TEXT("%d"), mapData.Num())
//	for (int i = 0; i < this->mapData.Num(); i++)
//	{
//		FMapData_Row* row = &mapData[i];
//		FString tmpMapRowInfo = "";
//		for (int j = 0; j < row->MapRow.Num(); j++)
//		{
//			tmpMapRowInfo += row->MapRow[j];
//			tmpMapRowInfo += "\t";
//		}
//		UE_LOG(LogTemp, Log, TEXT("Row: %s"), *tmpMapRowInfo);
//	}
//}

