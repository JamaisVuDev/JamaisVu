// Fill out your copyright notice in the Description page of Project Settings.

#include "SNE.h"
#include "CloneCharacter.h"
#include "SNECharacter.h"
#include <vector>

std::vector<ASNECharacter::Key> &inputs = ASNECharacter::inputs;
FRotator ACloneCharacter::SpawnRot;
FVector ACloneCharacter::SpawnLoc;
ACloneCharacter::ACloneCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	
	CloneMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("GenericMale"));
	CloneMesh->AttachParent = GetCapsuleComponent();
	//CloneMesh->RelativeLocation = FVector(0.f, 0.f, -150.f);
	CloneMesh->bCastDynamicShadow = false;
	CloneMesh->CastShadow = false;
}
void ACloneCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	SpawnLoc = ACloneCharacter::SpawnLoc;
	UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"), *SpawnLoc.ToString());
	

	/*UWorld* const World = GetWorld();
	if (World!=NULL){
	World->SpawnActor<ACloneCharacter>(ACloneCharacter::ACloneCharacter, SpawnLoc, SpawnRot);
	}
	*/

}
void ACloneCharacter::Move(FVector direction, float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(direction, Value);
	}
}

void ACloneCharacter::OnBeginCrouch()
{
	CharacterMovement->bWantsToCrouch = true;
}

void ACloneCharacter::OnStopCrouch()
{
	CharacterMovement->bWantsToCrouch = false;
}
