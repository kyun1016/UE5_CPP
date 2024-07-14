// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "PlayerBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UAnimMontage;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config = Game)
class OPENWORLD_3D_V0_3_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

		APlayerBase();

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true"))
		float MaxHealthPoint;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true"))
		float HealthPoint;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Attack", meta = (AllowPrivateAccess = "true"))
		float DamagePower;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Attack", meta = (AllowPrivateAccess = "true"))
		float CheckDistance;


	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float WalkSpeed;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float RunSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
		UAnimMontage* AnimAttackRun;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
		UAnimMontage* AnimAttackWalk;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
		UAnimMontage* AnimAttackIdle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
		float bAnimAttack;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputMappingContext* DefaultMappingContext;

	/** Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* ZoomAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* DashAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* AttackAction;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Zoom(const FInputActionValue& Value);
	void Dash(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);

	void AttackAnimation();
	UFUNCTION(BlueprintCallable, Category = "Animation")
		void AttackAnimationDone();
	void AttackLineTrace();
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Event")
	void AttackDone();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay();
};
