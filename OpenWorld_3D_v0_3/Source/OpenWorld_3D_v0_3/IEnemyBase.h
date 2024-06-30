// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEnemyBase.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIEnemyBase : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OPENWORLD_3D_V0_3_API IIEnemyBase
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetMovementSpeed() = 0;
	virtual void GetPatrolRoute() = 0;
	virtual void GetIdealRange() = 0;
	virtual void UnequipWeapon() = 0;
	virtual void EquipWeapon() = 0;
};
