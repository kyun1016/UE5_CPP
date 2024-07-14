// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem.h"

// Sets default values for this component's properties
UDamageSystem::UDamageSystem()
: MaxHealth(100.0f)
, Health(100.0f)
, bIsInvincible(false)
, bIsDead(false)
, bIsInterruptible(false)
, bIsBlocking(false)
{
}

