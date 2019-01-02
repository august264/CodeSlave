// Fill out your copyright notice in the Description page of Project Settings.

#include "MapManagerActor.h"
#include "ConstructorHelpers.h"
#include "GameModeBasic.h"

// Sets default values
AMapManagerActor::AMapManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Map size init
	mapSizeX = 10;
	mapSizeY = 10;

	tileSize = 16;

	rootScene = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent = rootScene;


	gridLine = CreateDefaultSubobject<UPaperTileMapComponent>("BuildGrid");
	gridLine->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	baseFloor = CreateDefaultSubobject<UPaperTileMapComponent>("FloorTiles");
	baseFloor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	constructionLayer = CreateDefaultSubobject<UPaperTileMapComponent>("ConstructionLayer");
	constructionLayer->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	baseWall = CreateDefaultSubobject<UPaperTileMapComponent>("WallTiles");
	baseWall->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<UPaperTileSet> obj(TEXT("PaperTileSet'/Game/2DSideScroller/Sprites/TileResource/City/CityTile_TileSet.CityTile_TileSet'"));

	if (obj.Succeeded()) 
	{
		this->baseTileSet = obj.Object;

		this->spawnableWallsAndFloors.Add(FString("GridLine"), 682);
		this->spawnableWallsAndFloors.Add(FString("TOP_LEFT_CORNER"), 102);
		this->spawnableWallsAndFloors.Add(FString("TOP_RIGHT_CORNER"), 103);
		this->spawnableWallsAndFloors.Add(FString("HORIZONTAL"), 100);
		this->spawnableWallsAndFloors.Add(FString("VERTICAL"), 138);
		this->spawnableWallsAndFloors.Add(FString("MID"), 30);
		this->spawnableWallsAndFloors.Add(FString("BOT"), 30);
		this->spawnableWallsAndFloors.Add(FString("BOT_LEFT_CORNER"), 139);
		this->spawnableWallsAndFloors.Add(FString("BOT_RIGHT_CORNER"), 140);
		this->spawnableWallsAndFloors.Add(FString("FLOOR"), 704);
	}

}

// Called when the game starts or when spawned
void AMapManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AMapManagerActor::getTileWorldPositon(int x, int y)
{
	FVector location = this->GetActorLocation();
	location += FVector(x*tileSize, y*tileSize, 0);
	return location;
}

FVector2D AMapManagerActor::getTileIndexFromWorldPosition(FVector pos)
{
	// Calculate the tile index for given in world location;
	FVector actorLoc = this->GetActorLocation();
	FVector diff = pos - actorLoc;
	FVector2D result = FVector2D(0, 0);
	AGameModeBasic* gameMode = (AGameModeBasic*)GetWorld()->GetAuthGameMode();

	if (gameMode) 
	{
		result.X = FMath::FloorToInt((diff.X + gameMode->getTileSizeX() / 2 )/ gameMode->getTileSizeX());
		result.Y = FMath::FloorToInt((diff.Y + gameMode->getTileSizeY() / 2 )/ gameMode->getTileSizeY());
	}
	return result;
}



void AMapManagerActor::TileMapSetUp()
{
	gridLine->CreateNewTileMap(mapSizeX, mapSizeY, tileSize, tileSize);
	baseFloor->CreateNewTileMap(mapSizeX, mapSizeY, tileSize, tileSize);
	constructionLayer->CreateNewTileMap(mapSizeX, mapSizeY, tileSize, tileSize);
	baseWall->CreateNewTileMap(mapSizeX, mapSizeY, tileSize, tileSize);
	//gridLine->AddRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	//baseFloor->AddRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));

	//gridLine->bVisible = false;
}

void AMapManagerActor::clearTileMap()
{
	
	for (int i = 0; i < mapSizeX; i++)
	{
		for (int j = 0; j < mapSizeY; j++)
		{
			constructionLayer->SetTile(i, j, 0, FPaperTileInfo());
		}
	}
}

