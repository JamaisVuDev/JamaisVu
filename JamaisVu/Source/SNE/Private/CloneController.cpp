// Fill out your copyright notice in the Description page of Project Settings.

#include "SNE.h"
#include "CloneController.h"
#include "EngineUtils.h"
#include "Engine.h"
#include "CloneCharacter.h"
#include "SNECharacter.h"
#include <vector>

std::vector<ASNECharacter::Key> &inputs = ASNECharacter::inputs;
FVector ACloneController::SpawnLoc;
FRotator ACloneController::SpawnRot;

ACloneController::ACloneController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void ACloneController::BeginPlay(){
	Super::BeginPlay();
	if (GEngine)
	{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}