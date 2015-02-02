// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SNE.h"
#include "SNEGameMode.h"
#include "SNEHUD.h"
#include "EngineUtils.h"
#include "Engine.h"
#include "SNECharacter.h"
#include "CloneCharacter.h"

ASNEGameMode::ASNEGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/MyCharacter"));

	DefaultPawnClass = PlayerPawnClassFinder.Class;
	
	// use our custom HUD class
	HUDClass = ASNEHUD::StaticClass();
}
FVector ASNEGameMode::SpawnLoc;
FRotator ASNEGameMode::SpawnRot;
UWorld* World;

void ASNEGameMode::StartPlay()
{
	Super::StartPlay();

	SpawnLoc = ASNECharacter::SpawnLoc;
	SpawnRot = ASNECharacter::SpawnRot;
	World = GetWorld();
	UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"), *SpawnLoc.ToString());

	/*
	if (World){
		//ACloneCharacter* Bot = (ACloneCharacter*)World->SpawnActor(ACloneCharacter::StaticClass(), SpawnLoc, SpawnRot);
		//ACloneCharacter* Bot = World->SpawnActor<ACloneCharacter>(ACloneCharacter::StaticClass(), SpawnLoc, SpawnRot);
		ACloneCharacter* Clone = World->SpawnActor<ACloneCharacter>(CloneClass, SpawnLoc, SpawnRot);
		
		//jfkh;oer9-=lUE_LOG(LogTemp, Warning, TEXT("Clone's Location is %s"), *(Bot->GetActorClass()).ToString());
	}
	*/
	
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}*/
	StartMatch();
}