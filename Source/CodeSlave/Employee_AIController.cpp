// Fill out your copyright notice in the Description page of Project Settings.

#include "Employee_AIController.h"

void AEmployee_AIController::BeginPlay() 
{
	Super::BeginPlay();

	for (int32 i = 0; i < 24; i++)
	{
		this->AISchedule[i] = &AEmployee_AIController::BehaviourEmpty;
	}

	// TODO assign blackboard and assign the behaviour tree
}

void AEmployee_AIController::Tick(float DeltaSec)
{
	int time = 1;	// TODO dummy variable, need to access in game time

	PlayBehaviour(time);

}

void AEmployee_AIController::PlayBehaviour(int32 scheduleIndex)
{
	(this->*(AISchedule[scheduleIndex]))();
}
