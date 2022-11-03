// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

bool UAbility::ActivateAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("Generic Ability Activated"));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Generic Ability Activated"));
	return true;
}
