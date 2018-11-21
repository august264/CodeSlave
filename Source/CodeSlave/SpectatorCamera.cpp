// Fill out your copyright notice in the Description page of Project Settings.

#include "SpectatorCamera.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/GameViewportClient.h"
#include "Engine.h"



ASpectatorCamera::ASpectatorCamera()
{
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	TopDownCameraComponent->OrthoWidth = 1024.0f;
	TopDownCameraComponent->SetupAttachment(RootComponent);

	TopDownCameraComponent->bUsePawnControlRotation = false;
	TopDownCameraComponent->bAutoActivate = true;

	TopDownCameraComponent->AspectRatio = (double)(38 / 30);

	this->CameraScrollBoundary = 25.0f;
	this->CameraPanningSpeed = 1.0f;

	PrimaryActorTick.bCanEverTick = true;

	this->mouseMidButtonPressed = false;


}

void ASpectatorCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Create Vector to hold the mouse position
	FVector2D mousePos;
	FVector2D viewportSize;
	// get ViewPort
	UGameViewportClient* viewport = GEngine->GameViewport;

	check(viewport);

	viewport->GetViewportSize(viewportSize);

	// make sure the viewport is focus
	if (viewport->IsFocused(viewport->Viewport) && viewport->GetMousePosition(mousePos)) 
	{
		if (!this->mouseMidButtonPressed)
		{
			// check the mouse is at the left or right edge of the screen
			if (mousePos.X < CameraScrollBoundary)
			{
				//move left
				this->MoveCameraRight(-1.0f * this->CameraPanningSpeed * DeltaSeconds);
			}
			else if (viewportSize.X - mousePos.X < CameraScrollBoundary)
			{
				// move right
				this->MoveCameraRight(1.0f * this->CameraPanningSpeed * DeltaSeconds);
			}

			// check the mouse is at the top or bottom edge of the screen
			if (mousePos.Y < CameraScrollBoundary)
			{
				// move up
				this->MoveCameraUp(-1.0f * this->CameraPanningSpeed * DeltaSeconds);
			}
			else if (viewportSize.Y - mousePos.Y < CameraScrollBoundary)
			{
				// move down
				this->MoveCameraUp(1.0f * this->CameraPanningSpeed * DeltaSeconds);
			}
		}
		else 
		{
			
			FVector2D deltaMovement = mouseOriginalPos - mousePos;
			FVector deltaPos = FVector(deltaMovement.X, deltaMovement.Y, 0.0f);
			DragCamera(deltaPos);
			mouseOriginalPos = mousePos;
		}
	}
}

void ASpectatorCamera::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Begin Play!"));
	// Acquire the player controller at the begin of the play
	this->playerController = UGameplayStatics::GetPlayerController((UObject*)GetWorld(), 0);
	EnableInput(this->playerController);
}

void ASpectatorCamera::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);

	check(InputComponent);
	InputComponent->BindAction("TestFunction", IE_Pressed, this, &ASpectatorCamera::PerfromTestFunction);
	InputComponent->BindAction("MiddleButtonPressed", IE_Pressed, this, &ASpectatorCamera::MiddleButtonPressed);
	InputComponent->BindAction("MiddleButtonReleased", IE_Released, this, &ASpectatorCamera::MiddleButtonReleased);
}

void ASpectatorCamera::MoveCameraRight(float deltaMovement)
{
	FVector deltaMov = deltaMovement * FVector(1.0f, 0.0f, 0.0f);
	//UE_LOG(LogTemp, Log, TEXT("Move %f, %f, %f "), deltaMov.X, deltaMov.Y, deltaMov.Z);
	FVector newLocation = this->GetActorLocation() + deltaMov;
	SetActorLocation(newLocation);
}


void ASpectatorCamera::MoveCameraUp(float deltaMovement)
{
	FVector deltaMov = deltaMovement * FVector(0.0f, 1.0f, 0.0f);
	//UE_LOG(LogTemp, Log, TEXT("Move %f, %f, %f "), deltaMov.X, deltaMov.Y, deltaMov.Z);
	FVector newLocation = this->GetActorLocation() + deltaMov;
	SetActorLocation(newLocation);
}

void ASpectatorCamera::DragCamera(FVector deltaPos) 
{
	FVector newLocation = this->GetActorLocation() + deltaPos;
	SetActorLocation(newLocation);
}

void ASpectatorCamera::MiddleButtonPressed()
{
	//Hererererererere
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Hello!")));

	UE_LOG(LogTemp, Log, TEXT("Middle mouse pressed = True"));
	FVector2D viewportSize;

	this->mouseMidButtonPressed = true;

	UGameViewportClient* viewport = GEngine->GameViewport;

	check(viewport);

	viewport->GetViewportSize(viewportSize);

	viewport->GetMousePosition(mouseOriginalPos);
	
}

void ASpectatorCamera::MiddleButtonReleased() 
{
	UE_LOG(LogTemp, Log, TEXT("Middle mouse pressed = False"));
	this->mouseMidButtonPressed = false;
}

//Herererererererere
void ASpectatorCamera::PerfromTestFunction() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("TestFunction!")));
	
}



