// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "SpectatorCamera.generated.h"


//Hererererererere
class UInputComponent;


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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
		class USceneComponent* scene;

	bool mouseMidButtonPressed;
	
public:

	

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

protected:


private:
	void MoveCameraRight(float deltaMovement);
	void MoveCameraUp(float deltaMovement);




private:

	FVector2D mouseOriginalPos;

public:

	ASpectatorCamera();

	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

public:

	UFUNCTION(blueprintCallable)
		void DragCamera(FVector deltaPos);

	// toggle the boolean variable to indicate whether the mid mouse button is pressed
	UFUNCTION(blueprintCallable)
		void toggleMidButtonPress() { this->mouseMidButtonPressed = !this->mouseMidButtonPressed; }

	UFUNCTION(blueprintCallable)
		void updateMousePosition();
};
