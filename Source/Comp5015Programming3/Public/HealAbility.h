// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "HealAbility.generated.h"

/**
 * 
 */
UCLASS()
class COMP5015PROGRAMMING3_API UHealAbility : public UAbility
{
	GENERATED_BODY()

	// Overriding UAbility's `ActivateAbility()` with our own ability activation:
	bool ActivateAbility() override;
};
