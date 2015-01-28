// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SNE.h"
#include "SNECharacter.h"
#include "SNEProjectile.h"
#include "Animation/AnimInstance.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////
// ASNECharacter

struct ASNECharacter::Key {
	FVector direction;
	float value;

	Key(FVector v, float va) : direction(v), value(va){}
};

std::vector<ASNECharacter::Key> ASNECharacter::inputs;
FVector ASNECharacter::SpawnLoc;
FRotator ASNECharacter::SpawnRot;

ASNECharacter::ASNECharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASNECharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//InputComponent->BindAction("W_Pressed", IE_Pressed, this, &ASNECharacter::W_Pressed);
	//InputComponent->BindAction("W_Released", IE_Released, this, &ASNECharacter::W_Released);

	InputComponent->BindAxis("MoveForward", this, &ASNECharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASNECharacter::MoveRight);
	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ASNECharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ASNECharacter::LookUpAtRate);

	// set up gameplay key bindings
	InputComponent->BindAction("Crouch", IE_Pressed, this, &ASNECharacter::OnBeginCrouch);
	InputComponent->BindAction("Crouch", IE_Released, this, &ASNECharacter::OnStopCrouch);
}

void ASNECharacter::MoveForward(float Value)
{

	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
		Key k(GetActorForwardVector(), Value);
		inputs.vector::push_back(k);
		UE_LOG(LogTemp, Warning, TEXT("Forward key added"));
	}
}

/*float current_W_PressTime = 0;
void ASNECharacter::W_Pressed()
{
	UE_LOG(LogTemp, Warning, TEXT("W down"));
	current_W_PressTime = this.GetWorld().UWorld::RealTimeSeconds;
}

void ASNECharacter::W_Released()
{
	UE_LOG(LogTemp, Warning, TEXT("W up"));
	Key myKey;
	myKey.pressTime = current_W_PressTime;
	myKey.releaseTime = UWorld::RealTimeSeconds();
}
*/
void ASNECharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
		Key k(GetActorForwardVector(), Value);
		inputs.vector::push_back(k);
		UE_LOG(LogTemp, Warning, TEXT("Side key added"));
	}
}

void ASNECharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASNECharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASNECharacter::OnBeginCrouch()
{
	CharacterMovement->bWantsToCrouch = true;
}

void ASNECharacter::OnStopCrouch()
{
	CharacterMovement->bWantsToCrouch = false;
}

