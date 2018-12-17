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
		FVector2D currentIndex = mapActor->getTileIndexFromWorldPosition(objToBuild->GetTransform().GetLocation());

		if (startIndex.X > endIndex.X) 
		{
			int tmp = endIndex.X;
			endIndex.X = startIndex.X;
			startIndex.X = tmp;
		}

		if (startIndex.Y > endIndex.Y) 
		{
			int tmp = endIndex.Y;
			endIndex.Y = startIndex.Y;
			startIndex.Y = tmp;
		}

		if (lastTickEndIndex != currentIndex)
		{
			mapActor->clearTileMap();
			indexArray.Empty();
			for (int i = startIndex.X; i <= (int)endIndex.X; i++)
			{
				for (int j = startIndex.Y; j <= (int)endIndex.Y; j++)
				{
					mapActor->constructionLayer->SetTile(i, j, 0, tmpInfo);
					indexArray.Add(FVector2D(i, j));
				}
			}
		}

		lastTickEndIndex = currentIndex;
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

void ASpectatorCamController::leftMouseButtonPressed()
{
	if (objToBuild)
	{
		UE_LOG(LogTemp, Log, TEXT("mouse left button pressed"));
		ObjOrignialPosition = objToBuild->GetTransform().GetLocation();
		if (objToBuild->getTileObjectType() == "Floor")
		{
			objPositionTracking = true;
		}
	}
}

void ASpectatorCamController::leftMouseButtonReleased()
{
	if (objToBuild)
	{
		if (objToBuild->getTileObjectType() != "Floor" && objToBuild->getTileObjectType() != "Wall")
		{
			UE_LOG(LogTemp, Log, TEXT("mouse left button released"));
			FActorSpawnParameters params;
			params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			const FTransform trans = objToBuild->GetTransform();
			GetWorld()->SpawnActor<ATileObject>(objToBuild->GetClass(), trans);
		}
		else
		{
			FPaperTileInfo tmpInfo = objToBuild->getSprite()->GetTile(0, 0, 0);
			objPositionTracking = false;
			mapActor->clearTileMap();
			for (int i = 0; i < indexArray.Num(); i++)
			{
				mapActor->baseFloor->SetTile((int)(indexArray[i].X), (int)(indexArray[i].Y), 0, tmpInfo);
			}
		}
	}
}

void ASpectatorCamController::rightMouseButtonPressed()
{
	if (objToBuild) 
	{

		objToBuild->Destroy();
	}
}

void ASpectatorCamController::rightMouseButtonReleased()
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


