// Fill out your copyright notice in the Description page of Project Settings.


#include "SXGameInstance.h"
#include "JsonObjectConverter.h"
#include "UObject/SavePackage.h"
#include "SXUnrealObject.h"
#include "Kismet/KismetSystemLibrary.h"

USXGameInstance::USXGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("USXGameInstance() has been called"))
}

void USXGameInstance::Init()
{
	Super::Init();

	USXUnrealObject* Object76 = NewObject<USXUnrealObject>();
	Object76->SetObjectName(TEXT("Object76"));
	Object76->SetObjectID(76);
	UE_LOG(LogTemp, Log, TEXT("[Object76] Name: %s, ID: %d"), *Object76->GetObjectName(), Object76->GetObjectID());

	const FString SavedDirectoryPath = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));
	const FString SavedFileName(TEXT("SerializedObject76JsonData.txt"));
	FString AbsoluteFilePath = FPaths::Combine(*SavedDirectoryPath, *SavedFileName);
	FPaths::MakeStandardFilename(AbsoluteFilePath);

	TSharedRef<FJsonObject> Object76JsonObject = MakeShared<FJsonObject>();
	FJsonObjectConverter::UStructToJsonObject(Object76->GetClass(), Object76, Object76JsonObject);

	FString WritedJsonString;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriterArchive = TJsonWriterFactory<TCHAR>::Create(&WritedJsonString);
	if (FJsonSerializer::Serialize(Object76JsonObject, JsonWriterArchive) == true)
	{
		FFileHelper::SaveStringToFile(WritedJsonString, *AbsoluteFilePath);
	}

	FString ReadedJsonString;
	FFileHelper::LoadFileToString(ReadedJsonString, *AbsoluteFilePath);
	TSharedRef<TJsonReader<TCHAR>> JsonReaderArchive = TJsonReaderFactory<TCHAR>::Create(ReadedJsonString);

	USXUnrealObject* ClonedObject76 = NewObject<USXUnrealObject>();

	TSharedPtr<FJsonObject> ClonedObject76JsonObject = nullptr;
	if (FJsonSerializer::Deserialize(JsonReaderArchive, ClonedObject76JsonObject) == true)
	{
		if (FJsonObjectConverter::JsonObjectToUStruct(ClonedObject76JsonObject.ToSharedRef(), ClonedObject76->GetClass(), ClonedObject76) == true)
		{
			UE_LOG(LogTemp, Log, TEXT("[ClonedObject76] Name: %s, ID: %d"), *ClonedObject76->GetObjectName(), ClonedObject76->GetObjectID());
		}
	}
}


void USXGameInstance::Shutdown()
{
	Super::Shutdown();
	UE_LOG(LogTemp, Log, TEXT("Shutdown() has been called"))

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Shutdown() has been called"));
}
