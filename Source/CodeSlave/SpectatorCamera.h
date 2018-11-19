// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "SpectatorCamera.generated.h"

/**
 * 
 */
UCLASS()
class CODESLAVE_API ASpectatorCamera : public ASpectatorPawn
{
	GENERATED_BODY()

private:

	/* Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Panning Params", meta = (AllowPrivateAccess = "true"))
		float CameraScrollBoundary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Panning Params", meta = (AllowPrivateAccess = "true"))
		float CameraPanningSpeed;

	bool mouseMidButtonPressed;
	
public:

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	void MoveCameraRight(float deltaMovement);
	void MoveCameraUp(float deltaMovement);
	void DragCamera(FVector deltaPos);

public:
	UFUNCTION()
	void MiddleButtonPressed();
	UFUNCTION()
	void MiddleButtonReleased();

private:

	FVector2D mouseOriginalPos;

public:

	ASpectatorCamera();

	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

protected:
	APlayerController * playerController;

};
