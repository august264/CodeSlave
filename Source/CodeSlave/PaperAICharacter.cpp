// Fill out your copyright notice in the Description page of Project Settings.

#include "PaperAICharacter.h"


// Sets default values
APaperAICharacter::APaperAICharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->CharacterMovement = CreateDefaultSubobject<UPawnMovementComponent>("Character Movement");

	this->collisionSphere = CreateDefaultSubobject<USphereComponent>("Collision Shpere");
	RootComponent = this->collisionSphere;

	this->motionAvatar = CreateDefaultSubobject<UPaperFlipbookComponent>("Motion Avatar");
	this->motionAvatar->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	this->staticAvatar = CreateDefaultSubobject<UPaperSpriteComponent>("Static Avatar");
	this->staticAvatar->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	

	// init TMaps for flipbooks and sprites
	motionFlipbooks.Add(FString("Walk_Up"));
	motionFlipbooks.Add(FString("Walk_Down"));
	motionFlipbooks.Add(FString("Walk_Left"));
	motionFlipbooks.Add(FString("Walk_Right"));

	staticSprite.Add(FString("Face_Up"));
	staticSprite.Add(FString("Face_Down"));
	staticSprite.Add(FString("Face_Left"));
	staticSprite.Add(FString("Face_Right"));
}

// Called when the game starts or when spawned
void APaperAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APaperAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


