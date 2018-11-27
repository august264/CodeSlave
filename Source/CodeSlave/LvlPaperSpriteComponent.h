// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "LvlPaperSpriteComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class CODESLAVE_API ULvlPaperSpriteComponent : public UPaperSpriteComponent
{
	GENERATED_BODY()

public:
	ULvlPaperSpriteComponent();
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = spriteLvl, meta = (AllowPrivateAccess = true))
		int32 spriteDisplayLevel;
	
};
