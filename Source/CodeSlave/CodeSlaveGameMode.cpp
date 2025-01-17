// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CodeSlaveGameMode.h"
#include "CodeSlaveCharacter.h"

ACodeSlaveGameMode::ACodeSlaveGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ACodeSlaveCharacter::StaticClass();	
}
