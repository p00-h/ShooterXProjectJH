// Fill out your copyright notice in the Description page of Project Settings.


#include "SXGameInstance.h"
#include "JsonObjectConverter.h"
#include "UObject/SavePackage.h"
#include "SXUnrealObject.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Example/SXFlyable.h"
#include "Example/SXPigeon.h"
#include "Example/SXEagle.h"

USXGameInstance::USXGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("USXGameInstance() has been called"))
}

void USXGameInstance::Init()
{
	Super::Init();
	
}


void USXGameInstance::Shutdown()
{
	Super::Shutdown();

}
