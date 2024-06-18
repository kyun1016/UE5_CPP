// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
	: TotalDamage(10)
	, DamageTimeInSeconds(1.2f)
	, DamagePerSecond(TotalDamage / DamageTimeInSeconds)
	, CharacterName(TEXT("Nickname"))
	, bAttackable(true)
{
	// DamagePerSecond = TotalDamage / DamageTimeInSeconds;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Log, TEXT("Constructor"));

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();

	CalcDPS();
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalcDPS();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AMyActor::CalcDPS()
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

void AMyActor::InputSpaceKey(bool Pressed)
{
	bPressedKey = Pressed;
}

void AMyActor::MoveUp(const float& DeltaTime)
{
	if (bPressedKey)
	{
		FVector Location = GetActorLocation();
		Location += FVector::UpVector * 980.0f * DeltaTime;
		SetActorLocation(Location);
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("Tick"));
}