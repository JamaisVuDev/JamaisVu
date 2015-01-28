// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "SNEGameMode.generated.h"

UCLASS(minimalapi)
class ASNEGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASNEGameMode(const FObjectInitializer& ObjectInitializer);
	static FVector* SpawnLoc;
	static FRotator* SpawnRot;
};



