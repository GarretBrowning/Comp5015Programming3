// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageAbility.h"

bool UDamageAbility::ActivateAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("Damage Ability Activated! (Overidden)"))
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Damage Ability Activated! (Overidden)"));
	return true;
}
