// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class OPENWORLD_3D_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Damage")
		int32 TotalDamage;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Damage")
		float DamageTimeInSeconds;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float DamagePerSecond;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FString CharacterName;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool bAttackable;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Move")
		bool bPressedKey;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitProperties() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	void CalcDPS();

	UFUNCTION(BlueprintCallable, Category = "Move")
		void InputSpaceKey(bool Pressed);
	UFUNCTION(BlueprintCallable, Category = "Move")
		void MoveUp(const float& DeltaTime);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
