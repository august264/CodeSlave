// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Employee.generated.h"

UENUM(BlueprintType)
enum class  EHealthCondition : uint8 
{
	EHealth_ill,
	EHealth_health,
	EHealth_NULL
};

UENUM(BlueprintType)
enum class EBodyCondition : uint8
{
	EBody_weak,
	EBody_healthy,
	EBody_fit,
	EBody_NULL
};

UENUM(BlueprintType)
enum class ESkill :uint8
{
	E_SKILL_SQL,
	E_SKILL_CPP,
	E_SKILL_C_SHARP,
	E_SKILL_PYTHON,
	E_SKILL_RUBY,
	E_SKILL_JAVA,
	E_SKILL_JAVASCRIPT,
	E_SKILL_PHP,
	E_SKILL_IOS,
	E_SKILL_NULL

};

UCLASS()
class CODESLAVE_API AEmployee : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEmployee();

	AEmployee(EBodyCondition _bCon, EHealthCondition _hCon, int _age, float _maxStamina, float exp, TArray<ESkill> _skills);
private:

	// Character component

	// flipbook
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Avatar", meta = (AllowPrivateAccess = true))
		UPaperFlipbookComponent* avatar;

	// collision box
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision", meta = (AllowPrivateAccess = true))
		UBoxComponent* collidingBox;

	// scene root
	UPROPERTY(BlueprintReadOnly, Category = "Scene", meta = (AllowPrivateAccess = true))
		USceneComponent* sceneComponent;


public:
	// FORCEINLINE GET FUNCTIONS
	FORCEINLINE class UPaperFlipbookComponent* getPaperFlipbookComponent() { return avatar; }
	FORCEINLINE class UBoxComponent* getBoxComponent() { return collidingBox; }
	FORCEINLINE class USceneComponent* getSceneComponent() { return sceneComponent; }

private:
	// parameters

	// skills
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		TArray<ESkill> skills;

	// the salary of the employee
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float salary;

	// the age of the employee
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		int age;

	// the stamina of the employee
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float stamina;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float maxStamina;

	// the health condition of the employee
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		EHealthCondition healthCondition;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		EBodyCondition bodyCondition;

	// the eyeCondition of the employee
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float eyesCondition;

	// the boldness of the employee, between 0(fully bold) to 1(fully not bold)
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float boldness;

	// the experience of the employee(years)
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float exp;

	// the efficiency when employee works, from 0 to 1
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float efficiency;

	// satisfaction, between 0 and 1
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float satisfaction;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Params", meta = (AllowPrivateAccess = true))
		float expectSalary;

public:
	// getters and setters

	// expect salary
	UFUNCTION(BlueprintCallable)
		float getExpectSalary() { return this->expectSalary; }
	UFUNCTION(BlueprintCallable)
		void setExpectSalary(float _expectSalary) { this->expectSalary = _expectSalary; }
	

	// satisfaction
	UFUNCTION(BlueprintCallable)
		float getSatisfaction() { return this->satisfaction; }
	UFUNCTION(BlueprintCallable)
		void setSatisfaction(float _satisfaction) { this->satisfaction = _satisfaction; }
	UFUNCTION(BlueprintCallable)
		void updateSatisfaction(float averageWorkingPercentage);


	// skills

	// remove certain skill
	// @return: if the skill is successfully removed return true, else return false;
	UFUNCTION(BlueprintCallable)
		bool removeSkill(ESkill skill);
	// add certain skill
	// @return: if the skill is successfully added return true, else return false;
	UFUNCTION(BlueprintCallable)
		bool addSkill(ESkill skill);

	// bodyCondition
	UFUNCTION(BlueprintCallable)
		void setBodyCondition(EBodyCondition condition) { this->bodyCondition = condition; }
	UFUNCTION(BlueprintCallable)
		EBodyCondition getBodyCondition() { return this->bodyCondition; }

	// salary
	UFUNCTION(BlueprintCallable)
		float getSalary() { return this->salary; }
	UFUNCTION(BlueprintCallable)
		void setSalary(float newSalary) { this->salary = newSalary >= 0 ? newSalary : this->salary; }
	
	// age
	UFUNCTION(BlueprintCallable)
		int getAge() { return this->age; }
	UFUNCTION(BlueprintCallable)
		void setAge(int newAge);

	// grow 1 year
	UFUNCTION(BlueprintCallable)
		void updateAge() { this->age += 1; }
	

	// stamina
	UFUNCTION(BlueprintCallable)
		void setMaximumStamina(float max) { this->maxStamina = max > 0 ? max : 0; }
	UFUNCTION(BlueprintCallable)
		float getMaximumStamina() { return this->maxStamina; }
	UFUNCTION(BlueprintCallable)
		float getStamina() { return this->stamina; }
	UFUNCTION(BlueprintCallable)
		void setStamina(float newStamina);

	// update the stamina for a delta value,(used for decrease stamina only!!!)
	UFUNCTION(BlueprintCallable)
		void updateStamina(float deltaVal);

	// restore the stamina
	UFUNCTION(BlueprintCallable)
		void restoreStamina();


	// health condition
	UFUNCTION(BlueprintCallable)
		EHealthCondition getHealthCondition() { return this->healthCondition; }
	UFUNCTION(BlueprintCallable)
		void setHealthCondition(EHealthCondition _condition) { this->healthCondition = _condition; }

	// eye condition
	UFUNCTION(BlueprintCallable)
		float getEyeCondition() { return this->eyesCondition; }
	UFUNCTION(BlueprintCallable)
		void setEyeCondition(float val) { this->eyesCondition = val; }

	// boldness
	UFUNCTION(BlueprintCallable)
		float getBoldness() { return this->boldness; }
	UFUNCTION(BlueprintCallable)
		void setBoldness(float val) { this->boldness = val >= 0 && val <= 1 ? val : this->boldness; }
	UFUNCTION(BlueprintCallable)
		void updateBoldness(float averageWorkingHr);
	
	// experience
	UFUNCTION(BlueprintCallable)
		float getExperience() { return this->exp; }
	UFUNCTION(BlueprintCallable)
		void setExperience(float val) { this->exp = val >= 0 ? val : this->exp; }
	UFUNCTION(BlueprintCallable)
		void addExperience(float val) { this->exp += val > 0 ? val : 0; }

	// @return the new efficiency
	UFUNCTION(BlueprintCallable)
		float getWorkingEfficiency() { return this->efficiency; };
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// utils functions

	// calculate the stamina restore efficiency based on ages
	float getRestoreEfficiency();

	// update working efficiency based on stamina
	void updateWorkingEfficiency();

	// hour sleep tracker, when weak up, reset the timer to zero, when sleep, add 1 to the timer every in game time unit
	float sleepTimer;
	
};
