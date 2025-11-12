// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SXTorch.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UPointLightComponent;
class UParticleSystemComponent;
class URotatingMovementComponent;

UCLASS()
class SHOOTERXPROJECTJH_API ASXTorch : public AActor
{
	GENERATED_BODY()

public:
	ASXTorch();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	//UPROPERTY(EditAnywhere)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SXTorch", Meta = (AllowPrivateAccess))
	TObjectPtr<UBoxComponent> BoxComponent;

	//UPROPERTY(EditAnywhere)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SXTorch", Meta = (AllowPrivateAccess))
	TObjectPtr<UStaticMeshComponent> BodyStaticMeshComponent;

	//UPROPERTY(EditAnywhere)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SXTorch", Meta = (AllowPrivateAccess))
	TObjectPtr<UPointLightComponent> PointLightComponent;

	//UPROPERTY(EditAnywhere)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SXTorch", Meta = (AllowPrivateAccess))
	TObjectPtr<UParticleSystemComponent> ParticleSystemComponent;

	//UPROPERTY(EditAnywhere, Category = "SXTorch")
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "SXTorch", Meta = (AllowPrivateAccess))
	int32 ID;

	UPROPERTY(VisibleInstanceOnly, Category = "SXTorch")
	uint8 bIsLit : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SXTorch", Meta = (AllowPrivateAccess))
	float RotationSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SXTorch", meta = (AllowPrivateAccess))
	TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;
	
};
