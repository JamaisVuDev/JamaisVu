// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CloneCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SNE_API ACloneCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* CloneMesh;
public:
	ACloneCharacter(const FObjectInitializer& ObjectInitializer);
	static FVector SpawnLoc;
	static FRotator SpawnRot;
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
protected:
	/** Handles moving forward/backward */
	void Move(FVector direction, float Val);
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UFUNCTION()
		void OnBeginCrouch();
	UFUNCTION()
		void OnStopCrouch();
	
};
