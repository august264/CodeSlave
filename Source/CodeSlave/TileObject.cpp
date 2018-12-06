// Fill out your copyright notice in the Description page of Project Settings.

#include "TileObject.h"
#include "Components/BoxComponent.h"


// Sets default values
ATileObject::ATileObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	rootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = rootScene;

	this->objectSprite = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("Object"));
	this->objectSprite->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
}

// Called when the game starts or when spawned
void ATileObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATileObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

