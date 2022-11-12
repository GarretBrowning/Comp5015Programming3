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

};
