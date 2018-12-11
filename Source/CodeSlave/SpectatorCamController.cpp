// Fill out your copyright notice in the Description page of Project Settings.

#include "SpectatorCamController.h"
#include "SpectatorCamera.h"

ASpectatorCamController::ASpectatorCamController()
{
}

void ASpectatorCamController::BeginPlay() 
{
	Super::BeginPlay();
	bShowMouseCursor = true;
}

void ASpectatorCamController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpectatorCamController::setObjToBuild(ATileObject * obj)
{
	this->objToBuild = obj;
	this->pendingObjectToBuild = true;
}

void ASpectatorCamController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);

	InputComponent->BindAction("MidMousePressed", IE_Pressed, this, &ASpectatorCamController::midMousePressed);
	InputComponent->BindAction("MidMouseReleased", IE_Released, this, &ASpectatorCamController::midMouseReleased);

	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &ASpectatorCamController::zoomIn);
	InputComponent->BindAction("ZoomOut", IE_Pressed, this, &ASpectatorCamController::zoomOut);
}

void ASpectatorCamController::midMousePressed()
{
	UE_LOG(LogTemp, Log, TEXT("mouse mid button pressed."));
	ASpectatorCamera* cam = (ASpectatorCamera*)Super::GetPawn();
	cam->toggleMidButtonPress();
	cam->updateMousePosition();
}

void ASpectatorCamController::midMouseReleased()
{
	UE_LOG(LogTemp, Log, TEXT("mouse mid button released"));
	ASpectatorCamera* cam = (ASpectatorCamera*)Super::GetPawn();
	cam->toggleMidButtonPress();
}

void ASpectatorCamController::zoomIn()
{
	ASpectatorCamera* cam = (ASpectatorCamera*)Super::GetPawn();
	cam->decreaseOrthoWidth();
}

void ASpectatorCamController::zoomOut()
{
	ASpectatorCamera* cam = (ASpectatorCamera*)Super::GetPawn();
	cam->increaseOrthoWidth();
}


