// Fill out your copyright notice in the Description page of Project Settings.

#include "Employee.h"


// Sets default values
AEmployee::AEmployee()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEmployee::setAge(int newAge)
{
	this->age = newAge >= 3 && newAge <= 100 ? newAge : this->age;
}

void AEmployee::setStamina(float newStamina)
{
	this->stamina = newStamina >= 0 ? newStamina : this->stamina;
	updateWorkingEfficiency();
}

void AEmployee::updateStamina(float deltaVal)
{
	this->stamina += this->stamina + deltaVal >= 0 ? deltaVal : 0;
	updateWorkingEfficiency();
}

void AEmployee::restoreStamina()
{
	float multiplier = 0;
	if (sleepTimer >= 1.5f && sleepTimer < 3.5f)
		multiplier = 1;
	else if (sleepTimer >= 3.5f && sleepTimer < 5.5f)
		multiplier = 2;
	else if (sleepTimer >= 5.5f && sleepTimer < 7.5f)
		multiplier = 3;
	else if (sleepTimer >= 7.5f)
		multiplier = 4;

	float restoration = multiplier * 25 * getRestoreEfficiency();
	if (this->stamina + restoration > this->maxStamina) 
	{
		this->stamina = this->maxStamina;
	}
	else 
	{
		this->stamina += restoration;
	}
}

// Called when the game starts or when spawned
void AEmployee::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmployee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEmployee::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEmployee::getRestoreEfficiency()
{
	float baseEfficiency = 1.0f;
	if (this->age <= 30) 
	{
		baseEfficiency = FMath::RandRange(0.85f, 0.9f);
	}
	else if (this->age > 30 && this->age < 45) 
	{
		baseEfficiency = FMath::RandRange(0.75f, 0.85f);
	}
	else 
	{
		baseEfficiency = FMath::RandRange(0.6f, 0.75f);
	}
	return baseEfficiency;
}

void AEmployee::updateWorkingEfficiency()
{
	this->efficiency =  0.9943f * this->stamina - 0.4023f;
}

