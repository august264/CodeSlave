// Fill out your copyright notice in the Description page of Project Settings.

#include "TESTAICharacter.h"
#include "PaperFlipbookComponent.h"

ATESTAICharacter::ATESTAICharacter()
{
	this->AvatarFlipbooks.Add("Walk_Up");
	this->AvatarFlipbooks.Add("Walk_Down");
	this->AvatarFlipbooks.Add("Walk_Left");
	this->AvatarFlipbooks.Add("Walk_Right");
	this->AvatarFlipbooks.Add("Static_Face_Up");
	this->AvatarFlipbooks.Add("Static_Face_Down");
	this->AvatarFlipbooks.Add("Static_Face_Left");
	this->AvatarFlipbooks.Add("Static_Face_Right");
	
	inMotion = false;

	CharacterFacing = ECharacterFacingEnum::E_DOWN;
	changeFacing = false;
	changeMotion = true;
}

void ATESTAICharacter::BeginPlay()
{
	Super::BeginPlay();
	this->characterLastLocation = this->GetActorLocation();
}

void ATESTAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector deltaLoc = this->GetActorLocation()- this->characterLastLocation;

	if (FMath::Abs(deltaLoc.X) >= FMath::Abs(deltaLoc.Y) && deltaLoc.X > 0)
	{
		if (CharacterFacing != ECharacterFacingEnum::E_RIGHT)
		{
			this->CharacterFacing = ECharacterFacingEnum::E_RIGHT;
			changeFacing = true;
		}
		else 
		{
			changeFacing = false;
		}
		
	}
	else if (FMath::Abs(deltaLoc.X) >= FMath::Abs(deltaLoc.Y) && deltaLoc.X < 0) 
	{
		if (CharacterFacing != ECharacterFacingEnum::E_LEFT)
		{
			this->CharacterFacing = ECharacterFacingEnum::E_LEFT;
			changeFacing = true;
		}
		else 
		{
			changeFacing = false;
		}
	}
	else if (FMath::Abs(deltaLoc.X) < FMath::Abs(deltaLoc.Y) && deltaLoc.Y > 0) 
	{
		if (CharacterFacing != ECharacterFacingEnum::E_DOWN)
		{
			this->CharacterFacing = ECharacterFacingEnum::E_DOWN;
			changeFacing = true;
		}
		else 
		{
			changeFacing = false;
		}
	}
	else if (FMath::Abs(deltaLoc.X) < FMath::Abs(deltaLoc.Y) && deltaLoc.Y < 0)
	{
		if (CharacterFacing != ECharacterFacingEnum::E_UP)
		{
			this->CharacterFacing = ECharacterFacingEnum::E_UP;
			changeFacing = true;
		}
		else
		{
			changeFacing = false;
		}
	}

	if (characterLastLocation != this->GetActorLocation()) 
	{
		if (!inMotion) 
		{
			inMotion = true;
			changeMotion = true;
		}
		else 
		{
			changeMotion = false;
		}
	}
	else 
	{
		if (inMotion) 
		{
			inMotion = false;
			changeMotion = true;
		}
		else 
		{
			changeMotion = false;
		}
	}

	if (changeMotion || changeFacing) 
	{
		switch (this->CharacterFacing)
		{
		case ECharacterFacingEnum::E_DOWN:
			FaceDown();
			break;
		case ECharacterFacingEnum::E_LEFT:
			FaceLeft();
			break;
		case ECharacterFacingEnum::E_RIGHT:
			FaceRight();
			break;
		case ECharacterFacingEnum::E_UP:
			FaceUp();
			break;
		default:
			break;
		}
	}

	characterLastLocation = this->GetActorLocation();

}

void ATESTAICharacter::FaceLeft()
{
	UPaperFlipbookComponent* sprite = this->GetSprite();

	if (inMotion) 
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Walk_Left"]);
	}
	else 
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Static_Face_Left"]);
	}
}

void ATESTAICharacter::FaceRight()
{
	UPaperFlipbookComponent* sprite = this->GetSprite();

	if (inMotion)
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Walk_Right"]);
	}
	else
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Static_Face_Right"]);
	}
}

void ATESTAICharacter::FaceUp()
{
	UPaperFlipbookComponent* sprite = this->GetSprite();

	if (inMotion)
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Walk_Up"]);
	}
	else
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Static_Face_Up"]);
	}
}

void ATESTAICharacter::FaceDown()
{
	UPaperFlipbookComponent* sprite = this->GetSprite();

	if (inMotion)
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Walk_Down"]);
	}
	else
	{
		sprite->SetFlipbook(this->AvatarFlipbooks["Static_Face_Down"]);
	}
}
