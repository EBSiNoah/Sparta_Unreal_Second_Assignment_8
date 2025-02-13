// Copyright Epic Games, Inc. All Rights Reserved.

#include "LoopAndUIrebuildGameMode.h"
#include "LoopAndUIrebuildCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALoopAndUIrebuildGameMode::ALoopAndUIrebuildGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
