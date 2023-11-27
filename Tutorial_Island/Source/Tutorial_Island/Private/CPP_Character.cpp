// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Character::RemovePickup()
{
	auto Temp = UGameplayStatics::GetPlayerCameraManager(this, 0);

	TArray<AActor *> Ignore;
	FVector Start = Temp->GetCameraLocation();
	FVector End = Start + (Temp->GetActorForwardVector() * 50000);
	FHitResult Hit;

	UKismetSystemLibrary::LineTraceSingle
	(
		this, 
		Start, 
		End, 
		ETraceTypeQuery::TraceTypeQuery1, 
		0, 
		Ignore, 
		EDrawDebugTrace::ForDuration, 
		Hit, 
		true
	);

	UKismetSystemLibrary::DrawDebugSphere
	(
		this,
		Hit.Location,
		50.0F,
		20,
		FLinearColor::Green,
		10.0F,
		2.0F
	);

	if(Hit.GetActor())
	{
		if(Cast<ACPP_Pickup>(Hit.GetActor()))
		{
			Hit.GetActor()->Destroy();
			UKismetSystemLibrary::PrintString(this, "Destroyed a Pickup");
		}
	}
}