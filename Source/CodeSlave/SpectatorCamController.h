// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TileObject.h"
#include "SpectatorCamController.generated.h"

/**
 * 
 */
UCLASS()
class CODESLAVE_API ASpectatorCamController : public APlayerController
{
	GENERATED_BODY()

public:
	ASpectatorCamController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void setObjToBuild(ATileObject* obj);

protected:
	bool pendingObjectToBuild;

	ATileObject* objToBuild;

protected:
	virtual void SetupInputComponent() override;

private:
	void midMousePressed();

	void midMouseReleased();

	UFUNCTION(BlueprintCallable)
	void zoomIn();

	UFUNCTION(BlueprintCallable)
	void zoomOut();
};
