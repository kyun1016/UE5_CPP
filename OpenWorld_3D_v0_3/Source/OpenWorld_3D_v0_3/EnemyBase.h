// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

class AWeaponBase;
DECLARE_DELEGATE(FDele_Single);

UCLASS()
class OPENWORLD_3D_V0_3_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Equip", meta = (AllowPrivateAccess = "true"))
	AWeaponBase* WeaponActor;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Equip", meta = (AllowPrivateAccess = "true"))
	bool bIsWieldingWeapon;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float MaxHealth;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float Health;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool bIsDead;

	FDele_Single Fuc_DeleSingle;
protected:

};
