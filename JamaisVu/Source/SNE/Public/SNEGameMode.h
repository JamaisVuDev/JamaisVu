// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "SNEGameMode.generated.h"

UCLASS(minimalapi)
class ASNEGameMode : public AGameMode
{
	GENERATED_BODY()
	virtual void StartPlay() override;
public:
	ASNEGameMode(const FObjectInitializer& ObjectInitializer);
	static FVector SpawnLoc;
	static FRotator SpawnRot;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ACloneCharacter> CloneClass;
};



