// Copyright Epic Games, Inc. All Rights Reserved.

#include "OpenWorld_3D_v0_3GameMode.h"
#include "OpenWorld_3D_v0_3Character.h"
#include "UObject/ConstructorHelpers.h"

AOpenWorld_3D_v0_3GameMode::AOpenWorld_3D_v0_3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
