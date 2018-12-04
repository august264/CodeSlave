// Fill out your copyright notice in the Description page of Project Settings.

#include "Employee.h"


// Sets default values
AEmployee::AEmployee()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->sceneComponent = CreateDefaultSubobject<USceneComponent>("root");
	//this->SetRootComponent(this->sceneComponent);
	inMotion = false;

	// animation
	this->MotionAvatar = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>("avatar");
	if (this->MotionAvatar)
	{
		MotionAvatar ->AlwaysLoadOnClient = true;
		MotionAvatar ->AlwaysLoadOnServer = true;
		MotionAvatar ->bOwnerNoSee = false;
		MotionAvatar ->bAffectDynamicIndirectLighting = true;
		MotionAvatar ->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		MotionAvatar ->bGenerateOverlapEvents = true;
		this->MotionAvatar->bVisible = false;
	}

	// static
	this->StaticAvatar = CreateOptionalDefaultSubobject<ULvlPaperSpriteComponent>("StaticAvatar");
	if (this->StaticAvatar) 
	{
		StaticAvatar->AlwaysLoadOnClient = true;
		StaticAvatar->AlwaysLoadOnServer = true;
		StaticAvatar->bOwnerNoSee = false;
		StaticAvatar->bAffectDynamicIndirectLighting = true;
		StaticAvatar->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		StaticAvatar->bGenerateOverlapEvents = true;
	}


	this->MotionAvatar ->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

	// collision box
	this->collidingBox = CreateOptionalDefaultSubobject<UBoxComponent>("CollsionBox");

	this->collidingBox->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	

	// disable all rotations
	this->bUseControllerRotationYaw = false;
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationRoll = false;

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

	originalPositon = this->GetActorLocation();
}


void AEmployee::updateSatisfaction(float averageWorkingPercentage)
{
	this->satisfaction = (salary / expectSalary) * 0.5f + (1 - averageWorkingPercentage)*0.5f;
}

void AEmployee::CharacterFaceRight()
{
	this->StaticAvatar->SetSprite(this->StaticRight);
}

void AEmployee::CharacterFaceLeft()
{
	this->StaticAvatar->SetSprite(this->StaticLeft);
}

void AEmployee::CharacterFaceUp()
{
	this->StaticAvatar->SetSprite(this->StaticUp);
}

void AEmployee::CharacterFaceDown()
{
	this->StaticAvatar->SetSprite(this->StaticDown);
}

bool AEmployee::removeSkill(ESkill skill)
{
	bool val = this->skills.Contains(skill);

	if (!val)
		return false;

	this->skills.Remove(skill);
	return true;
}

bool AEmployee::addSkill(ESkill skill)
{
	int val = this->skills.Contains(skill);

	if (val)
		return false;

	this->skills.AddUnique(skill);
	return true;
}

void AEmployee::setAge(int newAge)
{
	this->age = newAge >= 3 && newAge <= 100 ? newAge : this->age;
}

void AEmployee::setStamina(float newStamina)
{
	this->stamina = newStamina >= 0 && newStamina <= maxStamina ? newStamina : this->stamina;
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

void AEmployee::updateBoldness(float averageWorkingHr)
{
	this->boldness = FMath::Pow(averageWorkingHr, 2) / (105 - this->age) + 5;
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

	FVector newLocation = this->GetActorLocation();

	if (newLocation != originalPositon)
	{
		inMotion = true;
		FVector diff = newLocation - originalPositon;
		if (FMath::Abs(diff.X) > FMath::Abs(diff.Y))
		{
			if (diff.X > 0)
			{
				// face right
				this->MotionAvatar->SetFlipbook(MotionRight);
				this->StaticAvatar->SetSprite(StaticRight);
			}
			else if (diff.X < 0)
			{
				// face left
				this->MotionAvatar->SetFlipbook(MotionLeft);
				this->StaticAvatar->SetSprite(StaticLeft);
			}
		}
		else
		{
			if (diff.Y > 0)
			{
				// face down
				this->MotionAvatar->SetFlipbook(MotionDown);
				this->StaticAvatar->SetSprite(StaticDown);
			}
			else if (diff.Y < 0)
			{
				// face up
				this->MotionAvatar->SetFlipbook(MotionUp);
				this->StaticAvatar->SetSprite(StaticUp);
			}
		}
	}
	else 
	{
		inMotion = false;
	}

	if (inMotion) 
	{
		this->MotionAvatar->bVisible = true;
		this->StaticAvatar->bVisible = false;
	}
	else 
	{
		this->MotionAvatar->bVisible = false;
		this->StaticAvatar->bVisible = true;
	}
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




// 0 is female, 1 is male
void AEmployee::setEmployeeName(int gender) {

	if (gender == 0) {
		this->employeeName = FString(TEXT("Shanshan"));
	
	}

	else if (gender == 1) {
		this->employeeName = FString(TEXT("Vincent"));
	}


}
