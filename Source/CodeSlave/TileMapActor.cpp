// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMapActor.h"


// Sets default values
ATileMapActor::ATileMapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootScene = CreateDefaultSubobject<USceneComponent>("Root Component");

	RootComponent = rootScene;

	mapData = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("Tile Map"));

	mapData->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

}

// Called when the game starts or when spawned
void ATileMapActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATileMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATileMapActor::GenerateBaseMap()
{

	mapStringData.Empty();
	if (mapSizeX > 0 && mapSizeY > 0)
	{
		for (int i = 0; i < mapSizeX + 5; i++)
		{

			mapStringData.Add(FMapData_Row());
			//UE_LOG(LogTemp, Log, TEXT("x: %d"), mapStringData.Num());
			for (int j = 0; j < mapSizeY + 2; j++)
			{
				// Do not compress the IF statement by simply combine two statement with OR. the statements are not exclusive, the order of the excution is critial. 
				FString val;
				if (i == 0 && j == 0)
				{
					val = "TOP_LEFT_CORNER";
				}
				else if (i == 0 && j == mapSizeY + 1)
				{
					val = "TOP_RIGHT_CORNER";
				}
				else if (i == 0)
				{
					val = "HORIZONTAL";
				}
				else if (i >= 1 && i <= 2 && (j == 0 || j == mapSizeY + 1))
				{
					val = "VERTICAL";
				}
				else if (i >= i && i <= 2)
				{
					val = "MID";
				}
				else if (i == 3 && (j == 0 || j == mapSizeY + 1))
				{
					val = "VERTICAL";
				}
				else if (i == 3)
				{
					val = "BOT";
				}
				else if (i == mapSizeX + 4 - 3 && j == 0)
				{
					val = "BOT_LEFT_CORNER";
				}
				else if (i == mapSizeX + 4 - 3 && j == mapSizeY + 1)
				{
					val = "BOT_RIGHT_CORNER";
				}
				else if (i == mapSizeX + 4 - 3)
				{
					val = "HORIZONTAL";
				}
				else if (i >= mapSizeX + 4 - 2 && i <= mapSizeX + 4 - 1)
				{
					val = "MID";
				}
				else if (i == mapSizeX + 4)
				{
					val = "BOT";
				}
				else if (j == 0 || j == mapSizeY + 1)
				{
					val = "VERTICAL";
				}
				else
				{
					val = "FLOOR";
				}

				mapStringData[i].MapRow.Add(val);
			}
		}
	}
}

