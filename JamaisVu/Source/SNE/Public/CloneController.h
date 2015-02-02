// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CloneController.generated.h"

/**
 * 
 */
UCLASS()
class SNE_API ACloneController : public APlayerController
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	ACloneController(const FObjectInitializer& ObjectInitializer);
public:
	static FVector SpawnLoc;
	static FRotator SpawnRot;
	
	
	
};
