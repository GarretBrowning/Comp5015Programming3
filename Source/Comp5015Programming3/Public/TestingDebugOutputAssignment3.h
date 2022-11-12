// This class is solely used as a means to output testing debug logs of Item.h/cpp and ItemInventoryComponent.h/cpp methods.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.h"
#include "TestingDebugOutputAssignment3.generated.h"

/**
 * 
 */
UCLASS()
class COMP5015PROGRAMMING3_API UTestingDebugOutputAssignment3 : public UObject
{
	GENERATED_BODY()
	
	// Constructor:
	UTestingDebugOutputAssignment3();

	// Test Inventory Sizes:
	int MySmallSize{ 5 };
	int MyLargeSize{ 20 };

public:

	// Calls all testing functions for Item.h/cpp ItemInventoryComponent.h/cpp methods:
	void OutputDebugTestLogs();

	// --- ITEM TESTING --- //

	// Spawning an item using its default constructor:
	// - Ensuring that the Name, Attack, and Defence values are not set to NULL.
	// - Checking to see if the item displays the desired default data.
	void TestItemConstructor();

	// Initializing (setting) an item's Name, Attack and Defence values:
	// - Ensuring that the Name, Attack, and Defence values are not set to NULL.
	// - Checking to see if the item displays the desired default data.
	void TestItemInitialize();

	void TestGetAttackValue();
	void TestGetDefenceValue();
	void TestGetName();
	void TestGetIconImage(); // Not entirely sure what this is going to be used for yet.

	/* Returns true if they have the same Name, Attack & Defence values; otherwise, returns false.
	 * Should also return false if any parameter passed in is NULL. */
	void TestCompareItem();

	// --- ITEM INVENTORY COMPONENT TESTING --- //
	

	// Initializes the array of a given maximum size and sets each entry to NULL:
	void TestInitializeArray();

	// --- Array Operations ---
	// Returns the number of items currently in the array (does not count NULL entries):
	//int CountItems() const;
	void TestCountItems();


	// Does anything exist at a given index:
	void ContainsItemAtIndex();

	// Adds an item into the inventory array at the last open space, returns true if
	// it can be added, return false if it can't (no space because of MaxSize).
	void TestAddItem();

	// Tries to add at a given index, returns false if it cant. Don't replace.
	//bool AddItemAtIndex(int anIndex, UItem* aNewItem);
	void TestAddItemAtIndex();

	// TODO: --- Need to Implement Everything Below Here: ---
	// Retrieve non destructively:
	//UItem* GetItemAtIndex(int anIndex) const;
	void TestGetItemAtIndex();

	// Replace the item at the given index with a NewItem, returning a reference to the old one.
	//UItem* ReplaceItem(int anIndex, UItem* aNewItem);

	// removes and returns an Item* from the array
	//UItem* RemoveItem(int index);

	// Items are considered the same if the Name, Attack and Defence all match.
	// return -1 if it can't be found, otherwise return the index
	//int ContainsItem(UItem* TheItem);

	// If a matching Item is found, remove it. (Hint: Should be easy if you use existing functions!)
	//UItem* DropItem(UItem* TheItem);

	// --- Challenge --- (Optional)
	// Sorting methods that will change the order of the TArray Items.
	// After the function is run, the TArray will be in Alphabetical order (if sorted by name)
	// OR descending(High to Low) for the int values.
		// Either:
		// 1. Create your own sorting function or
		// 2. Custom Iterator for TArray Sort function
	//void SortByAttack();
	//void SortByDefence();
	//void SortByName();

};
