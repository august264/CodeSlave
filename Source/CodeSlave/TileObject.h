// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperTileMapComponent.h"
#include "Components/BillboardComponent.h"
#include "TileObject.generated.h"

UCLASS()
class CODESLAVE_API ATileObject : public AActor
{
	GENERATED_BODY()
	
private:
	// indicate whether other object can be overlapped onto this tile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TileSettings, meta = (AllowPrivateAccess = true))
		bool bAllowTileOverlap;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Scene, meta = (AllowPrivateAccess = true))
		class USceneComponent* rootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Sprite, meta = (AllowPrivateAccess = true))
		class UPaperTileMapComponent* objectSprite;

	// Store the string indicates what kind of object is this, used for casting to correct object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ObjectData, meta = (AllowPrivateAccess = true))
		FString ObjectTypes;

	// Store the string that is a key to access the character motion
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ObjectData, meta = (AllowPrivateAccess = true))
		FString InteractiveAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = ObjectData, meta = (AllowPrivateAccess = true))
		UBillboardComponent* targetPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = ObjectData, meta = (AllowPrivateAccess = true))
		bool bOccupied;

public:
	UFUNCTION(BlueprintCallable)
		FString getTileObjectType() { return ObjectTypes; }

	UFUNCTION(BlueprintCallable)
		FString getInteractiveAction() { return InteractiveAction; }
public:	
	// Sets default values for this actor's properties
	ATileObject();

	FORCEINLINE UBillboardComponent* getTargetPoint() { return targetPoint; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
	
};
