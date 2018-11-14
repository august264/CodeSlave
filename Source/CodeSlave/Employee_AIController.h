// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Employee_AIController.generated.h"

/**
 * 
 */
UCLASS()
class CODESLAVE_API AEmployee_AIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

};
