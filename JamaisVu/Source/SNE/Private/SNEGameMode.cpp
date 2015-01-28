// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SNE.h"
#include "SNEGameMode.h"
#include "SNEHUD.h"
#include "EngineUtils.h"
#include "SNECharacter.h"
#include "CloneCharacter.h"

ASNEGameMode::ASNEGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/MyCharacter"));

	DefaultPawnClass = PlayerPawnClassFinder.Class;
	UWorld* const World = GetWorld();
	//FVector* SpawnLoc;
	//FRotator* SpawnRot;
	/*
	for (TActorIterator<> ActorItr(World); ActorItr; ++ActorItr)
	{
		if (ActorItr->HasTag("start"))
		{
			SpawnLoc = &ActorItr->GetActorLocation();
			SpawnRot = &ActorItr->GetControlRotation();
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"), *loc.ToString());

	if (World){
		ACloneCharacter* Bot = (ACloneCharacter*) World->SpawnActor(ACloneCharacter::StaticClass(), SpawnLoc, SpawnRot);
		if (Bot) {
			//UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"), *spawn.ToString());
		}
	}
	*/
	// use our custom HUD class
	HUDClass = ASNEHUD::StaticClass();
}
