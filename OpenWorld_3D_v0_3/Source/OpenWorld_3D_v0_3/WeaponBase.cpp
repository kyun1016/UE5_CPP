// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	SetRootComponent(StaticMesh);
	// StaticMesh->SetMobility(EComponentMobility::Movable);
	// StaticMesh->GetBodyInstance()->bUseCCD = true;
	StaticMesh->SetCollisionProfileName("NoCollision");
}
