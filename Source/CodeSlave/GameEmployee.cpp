// Fill out your copyright notice in the Description page of Project Settings.

#include "GameEmployee.h"


AGameEmployee::AGameEmployee() 
{

	// Random generate params
	this->setBodyCondition(EBodyCondition(FMath::RandRange(0, 2)));
	this->setAge(FMath::RandRange(18, 60));
	this->setHealthCondition(EHealthCondition(FMath::RandRange(0, 1)));
	this->setExperience(FMath::RandRange(0, 16));
	this->addSkill(ESkill(FMath::RandRange(0, 8)));
	this->addSkill(ESkill(FMath::RandRange(0, 8)));
	this->addSkill(ESkill(FMath::RandRange(0, 8)));
	this->addSkill(ESkill(FMath::RandRange(0, 8)));
	this->satisfaction = FMath::RandRange(0.5f, 0.8f);
}



void AGameEmployee::BeginPlay()
{

	Super::BeginPlay();
}

void AGameEmployee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameEmployee::updateSatisfaction(float averageWorkingPercentage)
{
	this->satisfaction = (salary / expectSalary) * 0.5f + (1 - averageWorkingPercentage)*0.5f;
}

bool AGameEmployee::removeSkill(ESkill skill)
{
	bool val = this->skills.Contains(skill);

	if (!val)
		return false;

	this->skills.Remove(skill);
	return true;
}

bool AGameEmployee::addSkill(ESkill skill)
{
	int val = this->skills.Contains(skill);

	if (val)
		return false;

	this->skills.AddUnique(skill);
	return true;
}

void AGameEmployee::setAge(int newAge)
{
	this->age = newAge >= 3 && newAge <= 100 ? newAge : this->age;
}

void AGameEmployee::setStamina(float newStamina)
{
	this->stamina = newStamina >= 0 && newStamina <= maxStamina ? newStamina : this->stamina;
	updateWorkingEfficiency();
}

void AGameEmployee::updateStamina(float deltaVal)
{
	this->stamina += this->stamina + deltaVal >= 0 ? deltaVal : 0;
	updateWorkingEfficiency();
}

void AGameEmployee::restoreStamina()
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

void AGameEmployee::updateBoldness(float averageWorkingHr)
{
	this->boldness = FMath::Pow(averageWorkingHr, 2) / (105 - this->age) + 5;
}

float AGameEmployee::getRestoreEfficiency()
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

void AGameEmployee::updateWorkingEfficiency()
{
	this->efficiency = 0.9943f * this->stamina - 0.4023f;
}




// 0 is female, 1 is male
void AGameEmployee::setEmployeeName(int gender) {

	if (gender == 0) {
		this->employeeName = FString(TEXT("Shanshan"));

	}

	else if (gender == 1) {
		this->employeeName = FString(TEXT("Vincent"));
	}


}
