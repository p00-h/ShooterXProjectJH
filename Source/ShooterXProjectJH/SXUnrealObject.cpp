// Fill out your copyright notice in the Description page of Project Settings.


#include "SXUnrealObject.h"

USXUnrealObject::USXUnrealObject()
{
	Name = TEXT("USXUnrealObject CDO");
}

void USXUnrealObject::HelloUnreal()
{
	UE_LOG(LogTemp, Log, TEXT("USXUnrealObject::HelloUnreal() has been called"));
}

void USXUnrealObject::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	Ar << Name;
	Ar << ID;
}