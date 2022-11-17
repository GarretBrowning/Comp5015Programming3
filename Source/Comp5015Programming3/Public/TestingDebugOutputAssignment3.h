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

	// Test Inventory Size:
	int MySmallSize{ 5 };

public:

	// Calls all testing functions for Item.h/cpp and ItemInventoryComponent.h/cpp methods:
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

	// Creating a test item, setting its default values, and checking to see if we can retrieve its Attack Value:
	void TestGetAttackValue();

	// Creating a test item, setting its default values, and checking to see if we can retrieve its Defence Value:
	void TestGetDefenceValue();

	// Creating a test item, setting its default values, and checking to see if we can retrieve its Name:
	void TestGetName();

	// Because there is no member variable within our Item class that holds a PaperSprite object, we will leave this for now...
	void TestGetIconImage();

	// Creating 3 test items (Unique Item, Unique Item, Duplicate of 2nd Item).
	// Comparing Unique Item vs. Unique Item (Expecting Equal = False).
	// Comparing Unique Item vs. Duplicate of 2nd Item (Expecting Equal = True).
	void TestCompareItem();
	// ------------------------------------------------------------------------------------------------------- //

	// --- ITEM INVENTORY COMPONENT TESTING --- //

	// Creating an empty inventory and proving that it has empty contents:
	void TestInitializeArray();

	// Creates an empty inventory along with a new item. Adds the item to the inventory.
	// Counts the contents of the inventory after placing the item within it. Should return with a value of 1.
	void TestCountItems();

	// Creates an empty inventory along with a new item. Adds the item to the inventory at a specific index [0].
	// Checks to see if the item is at the specified index [0]. Should return True.
	void TestContainsItemAtIndex();

	// Creates an empty inventory along with a new item.
	// Checks afterwards to see if the item has been succesfully added in the last available open slot.
	// Should return successful.
	void TestAddItem();

	// Creates an empty inventory along with a new item. Adds the item to the inventory at a specific index [2].
	// Checks to see if the item is at the specified index [2]. Should return True.
	void TestAddItemAtIndex();

	// Creates an empty inventory along with a new item. Adds the item to the inventory at a specific index [1].
	// Checks to see if the item at the specified index [1] is a valid item that can be returned.
	// Should return the desired item.
	void TestGetItemAtIndex();

	// Creates an empty inventory along with 2 unique items. Adds one item to the inventory at index[1].
	// Checks to see if the 2nd unique item replaces the original item placed at index[1].
	// Should return the previous item as well as the new item replacing it at index[1].
	void TestReplaceItem();

	// Creates an empty inventory along with a new item. Adds the item to the inventory at a specific index [3].
	// Checks to see if the item at the specified index [3] is a valid item that can be removed.
	// Should return the desired item which has been removed.
	void TestRemoveItem();

	// Creates an empty inventory along with a new item. Adds the item to the inventory.
	// Checks to see if the item is contained within the inventory.
	// Should return that the item was found.
	void TestContainsItem();

	// Creates an empty inventory along with a new item. Adds the item to the inventory.
	// Checks to see if the item is contained within the inventory. If so, removes it.
	// Should return that the item was found and removed.
	void TestDropItem();

	// Creates an empty inventory along with a 4 unique items. Adds the items to the inventory.
	// Sorts the inventory by Attack. Outputs the previous inventory contents and the newly sorted contents (by Attack):
	void TestSortByAttack();

	// Creates an empty inventory along with a 4 unique items. Adds the items to the inventory.
	// Sorts the inventory by Defence. Outputs the previous inventory contents and the newly sorted contents (by Defence):
	void TestSortByDefence();

	// Creates an empty inventory along with a 4 unique items. Adds the items to the inventory.
	// Sorts the inventory by Name. Outputs the previous inventory contents and the newly sorted contents (by Name):
	void TestSortByName();
};
