// Fill out your copyright notice in the Description page of Project Settings.


#include "HealAbility.h"

bool UHealAbility::ActivateAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("Heal Ability Activated! (Overidden)"))
	return true;
}
