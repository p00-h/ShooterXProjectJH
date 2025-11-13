// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SXGameModeBase.h"

#include "Character/SXPlayerPawn.h"
#include "ShooterXProjectJH/Controller/SXPlayerController.h"

ASXGameModeBase::ASXGameModeBase()
{
	PlayerControllerClass = ASXGameModeBase::StaticClass();
	DefaultPawnClass = ASXPlayerPawn::StaticClass();
}

