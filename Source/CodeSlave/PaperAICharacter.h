// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/SphereComponent.h"
#include "PaperAICharacter.generated.h"

UCLASS()
class CODESLAVE_API APaperAICharacter : public APawn
{
	GENERATED_BODY()

		// essential components
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = true))
		UCharacterMovementComponent* CharacterMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = RootScene, meta = (AllowPrivateAccess = true))
		USceneComponent* rootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Avatar, meta = (AllowPrivateAccess = true))
		UPaperFlipbookComponent* motionAvatar;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Avatar, meta = (AllowPrivateAccess = true))
		UPaperSpriteComponent* staticAvatar;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Avatar, meta = (AllowPrivateAccess = true))
		USphereComponent* collisionSphere;

	// class data
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = motionData, meta = (AllowPrivateAccess = true))
		TMap<FString, UPaperFlipbook*> motionFlipbooks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = motionData, meta = (AllowPrivateAccess = true))
		TMap<FString, UPaperSprite*> staticSprite;

public:
	// Sets default values for this pawn's properties
	APaperAICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
