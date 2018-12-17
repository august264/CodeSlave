// Fill out your copyright notice in the Description page of Project Settings.

#include "SpectatorCamController.h"
#include "GameModeBasic.h"
#include "SpectatorCamera.h"

ASpectatorCamController::ASpectatorCamController()
{
}

void ASpectatorCamController::BeginPlay() 
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	// get map actor from world
	AGameModeBasic* gameMode = (AGameModeBasic*)(GetWorld()->GetAuthGameMode());

	mapActor = gameMode->getCurrentInGameMap();
}

void ASpectatorCamController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (objPositionTracking) 
	{
		// acquire mapActor floor tileMap
		FPaperTileInfo tmpInfo = objToBuild->getSprite()->GetTile(0, 0, 0);
		
		FVector2D startIndex = mapActor->getTileIndexFromWorldPosition(ObjOrignialPosition);
		FVector2D endIndex = mapActor->getTileIndexFromWorldPosition(objToBuild->GetTransform().GetLocation());

		if (lastTickEndIndex != endIndex)
		{
			mapActor->clearTileMap();
			for (int i = startIndex.X; i < (int)endIndex.X; i++)
			{
				for (int j = startIndex.Y; j < (int)endIndex.Y; j++)
				{
					mapActor->baseFloor->SetTile(i, j, 0, tmpInfo);
				}
			}
		}

		lastTickEndIndex = endIndex;
	}

	

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

	InputComponent->BindAction("RightMouseButtonPressed", IE_Pressed, this, &ASpectatorCamController::rightMouseButtonPressed);
	InputComponent->BindAction("RightMouseButtonReleased", IE_Released, this, &ASpectatorCamController::rightMouseButtonReleased);

	InputComponent->BindAction("MidMousePressed", IE_Pressed, this, &ASpectatorCamController::midMousePressed);
	InputComponent->BindAction("MidMouseReleased", IE_Released, this, &ASpectatorCamController::midMouseReleased);

	InputComponent->BindAction("LeftMouseButtonPressed", IE_Pressed, this, &ASpectatorCamController::leftMouseButtonPressed);
	InputComponent->BindAction("LeftMouseButtonReleased", IE_Released, this, &ASpectatorCamController::leftMouseButtonReleased);

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

void ASpectatorCamController::rightMouseButtonPressed()
{
	UE_LOG(LogTemp, Log, TEXT("mouse right button pressed"));
	ObjOrignialPosition = objToBuild->GetTransform().GetLocation();
	if (objToBuild->getTileObjectType == "Floor")
	{
		objPositionTracking = true;
	}
}

void ASpectatorCamController::rightMouseButtonReleased()
{
	UE_LOG(LogTemp, Log, TEXT("mouse right button released"));

	if (objToBuild->getTileObjectType != "Floor" || objToBuild->getTileObjectType != "Wall") 
	{
		FActorSpawnParameters params;
		const FTransform trans = objToBuild->GetTransform();
		GetWorld()->SpawnActor<ATileObject>(objToBuild->StaticClass(), trans);
	}
	else 
	{
		objPositionTracking = false;
	}
}

void ASpectatorCamController::leftMouseButtonPressed()
{
	if (objToBuild) 
	{
		objToBuild->Destroyed();
	}
}

void ASpectatorCamController::leftMouseButtonReleased()
{
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


