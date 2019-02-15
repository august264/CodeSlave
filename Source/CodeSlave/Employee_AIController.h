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

private:

	typedef void (AEmployee_AIController::*funcPtr)(void);

	funcPtr AISchedule[24];

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSec) override;

	void PlayBehaviour(int32 scheduleIndex);

private:

	virtual void BehaviourEmpty() {};
};
