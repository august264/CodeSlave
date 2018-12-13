// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbook.h"
#include "TESTAICharacter.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECharacterFacingEnum : uint8 
{
	E_UP	UMETA(DisplayName = "Face Up"),
	E_DOWN	UMETA(DisplayName = "Face Down"),
	E_LEFT	UMETA(DisplayName = "Face Left"),
	E_RIGHT UMETA(DisplayName = "Face Right")
};

UCLASS()
class CODESLAVE_API ATESTAICharacter : public APaperCharacter
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Flipbooks", meta = (AllowprivateAccess = true))
		TMap<FString, UPaperFlipbook*> AvatarFlipbooks;

	UPROPERTY(BlueprintReadOnly)
	bool inMotion;
	UPROPERTY(BlueprintReadOnly)
	bool changeFacing;
	UPROPERTY(BlueprintReadOnly)
	bool changeMotion;

	UPROPERTY(BlueprintReadOnly)
	ECharacterFacingEnum CharacterFacing;

public:
	ATESTAICharacter();

	UFUNCTION(BlueprintCallable)
		void excuteAction(FString action);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FVector characterLastLocation;
	
protected:

	void FaceLeft();

	void FaceRight();

	void FaceUp();

	void FaceDown();
};
