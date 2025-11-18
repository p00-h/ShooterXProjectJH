// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/SXWeapon.h"

#include "Character/SXPlayerCharacter.h"
#include "Component/SXPickupComponent.h"

ASXWeapon::ASXWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	PickupComponent = CreateDefaultSubobject<USXPickupComponent>(TEXT("PickupComponent"));
	SetRootComponent(PickupComponent);
}

void ASXWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	PickupComponent->OnPickUp.AddDynamic(this, &ThisClass::HandleOnPickUp);
}

void ASXWeapon::HandleOnPickUp(ASXPlayerCharacter* InPickUpCharacter)
{
	if (IsValid(InPickUpCharacter) == false)
	{
		return;
	}

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	AttachToComponent(InPickUpCharacter->GetMesh(), AttachmentRules, FName(TEXT("hand_rSocket")));
	SetActorEnableCollision(false);
	PickupComponent->SetSimulatePhysics(false);	
}




