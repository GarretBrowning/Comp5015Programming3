// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Components/ActorComponent.h"
#include "ItemInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMP5015PROGRAMMING3_API UItemInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	// TArray MUST have a UPROPERTY to mark it for memory management (aka garbage collection).
	UPROPERTY(Instanced, EditAnywhere, Category = "Items")
	TArray<UItem*> MyItems;

	int MyMaxSize{ 10 }; // Arbitary starting size of inventory.

public:	
	// Sets default values for this component's properties
	UItemInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Initializes the array of a given maximum size and sets each entry to NULL:
	void InitializeArray(int aMaxSize);

	// --- Array Operations ---
	// Returns the maximum size of the item inventory (includes NULL entries):
	int GetMaxSize() const;

	// Returns the number of items currently in the array (does not count NULL entries):
	int CountItems() const;

	// Does anything exist at a given index:
	bool ContainsItemAtIndex(int anIndex) const;

	// Adds an item into the inventory array at the last open space, returns true if
	// it can be added, return false if it can't (no space because of MaxSize).
	bool AddItem(UItem* aNewItem);

	// Tries to add at a given index, returns false if it cant. Don't replace.
	bool AddItemAtIndex(int anIndex, UItem* aNewItem);

	// Retrieve non destructively:
	UItem* GetItemAtIndex(int anIndex) const;

	// Replace the item at the given index with a NewItem, returning a reference to the old one.
	UItem* ReplaceItem(int anIndex, UItem* aNewItem);

	// Removes and returns an Item* from the array
	UItem* RemoveItem(int anIndex);

	// Items are considered the same if the Name, Attack and Defence all match.
	// return -1 if it can't be found, otherwise return the index
	int ContainsItem(UItem* anItem);

	// If a matching Item is found, remove it. (Hint: Should be easy if you use existing functions!)
	UItem* DropItem(UItem* anItem);

	// --- Challenge --- (Optional)
	// Sorts the inventory by Attack (highest to lowest).
	void SortByAttack();

	// Sorts the inventory by Defence (highest to lowest).
	void SortByDefence();

	// Sorts the inventory by Name (alphabetical order).
	void SortByName();

};
