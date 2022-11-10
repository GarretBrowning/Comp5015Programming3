// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * The base item class for the inventory system.
 */
UCLASS()
class COMP5015PROGRAMMING3_API UItem : public UObject
{
	GENERATED_BODY()

	// Constructor:
	UItem();

public:
	// --- Item Base Properties ---
	// Name of the item:
	UPROPERTY(EditDefaultsOnly, Category = "Item | Base Traits")
	FName MyName;

	// Attack damage value of the item:
	UPROPERTY(EditDefaultsOnly, Category = "Item | Base Traits")
	int MyAttackValue{ 0 };

	// Defending damage block value of the item:
	UPROPERTY(EditDefaultsOnly, Category = "Item | Base Traits")
	int MyDefenceValue{ 0 };

	// --- Item Base Functions ---
	// Sets the initial values of the item.
	// Additionally has default values set.
	void Initialize(FName aName = "???", int anAttackValue = 0, int aDefenceValue = 0);

	// Accessors:
	int GetAttackValue();
	int GetDefenceValue();
	FName GetName();

	class UPaperSprite* GetIconImage(); // Not entirely sure what this is going to be used for yet.

	/* Returns true if they have the same Name, Attack & Defence values; otherwise, returns false.
	 * Should also return false if any parameter passed in is NULL. */
	static bool CompareItem(UItem* anItem, UItem* anItemToCompare);

//private:
	// Output the item details:
	FString ToString();
};
