// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Ability.generated.h"

/**
 * 
 */
UCLASS()
class COMP5015PROGRAMMING3_API UAbility : public UObject //, public FTickableGameObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Ability|Generic")
	FName AbilityName = TEXT("GENERIC ABILITY");

	// Is this ability available to this character?
	UPROPERTY(EditDefaultsOnly, Category = "Ability|Generic")
	bool bHasAbility = false;

	// Not sure what this property is for yet...
	UPROPERTY(EditDefaultsOnly, Category = "Ability|Generic")
	int AbilityAmount = 1;

public:
	// (Making this a bool so we can return false in case it fails)
	// This is the generic ability.
	// Technically not a pure Abstract function as we are providing a default implementation:
	UFUNCTION(BlueprintCallable, Category = "Ability|Generic")
	virtual bool ActivateAbility();
};
/*
protected:
	virtual bool bActivateAbility();
	virtual bool bIsAbilityReady();
	virtual void ActivateAbility();

	/////////////////////////////////////////////////////////////////////
	///// https://benui.ca/unreal/tickable-object/
public:
	
	// FTickableGameObject Begin
	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FMyTickableThing, STATGROUP_Tickables);
	}
	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}
	virtual bool IsTickableInEditor() const
	{
		return false;
	}
	// FTickableGameObject End

private:
	// The last frame number we were ticked.
		// We don't want to tick multiple times per frame 
	uint32 LastFrameNumberWeTicked = INDEX_NONE;
////////////////////////////////////////////////////////////////////*/