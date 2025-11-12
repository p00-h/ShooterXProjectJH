// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SXUnrealObject.generated.h"

/**
 * 
 */
USTRUCT()
struct FSXUnrealObjectData
{
	GENERATED_BODY()

public:
	FSXUnrealObjectData()
	{
			
	}

	FSXUnrealObjectData(const FString& InName, int32 InID)
		:Name(InName)
		,ID(InID)
	{
			
	}

	friend FArchive& operator<<(FArchive& InArchive, FSXUnrealObjectData& InUnrealObjectData)
	{
		InArchive << InUnrealObjectData.Name;
		InArchive << InUnrealObjectData.ID;
		return InArchive;
	}

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 ID;

};

UCLASS()
class SHOOTERXPROJECTJH_API USXUnrealObject : public UObject
{
	GENERATED_BODY()

public:
	USXUnrealObject();

	UFUNCTION()
	void HelloUnreal();

	const FString& GetObjectName() const { return Name; }
	void SetObjectName(const FString& InName) { Name = InName; }

	int32 GetObjectID() const { return ID; }
	void SetObjectID(const int32& InID) { ID = InID; }

	virtual void Serialize(FArchive& Ar) override;
	
protected:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 ID;
	
};
