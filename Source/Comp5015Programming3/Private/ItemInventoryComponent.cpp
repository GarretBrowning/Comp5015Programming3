// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemInventoryComponent.h"
#include "TestingDebugOutputAssignment3.h" // For Debug Testing.

// Sets default values for this component's properties
UItemInventoryComponent::UItemInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UItemInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	//-Debug-Testing-//
	UTestingDebugOutputAssignment3* Debugger = NewObject<UTestingDebugOutputAssignment3>();
	Debugger->OutputDebugTestLogs();
	//--------------//
}

// Called every frame
void UItemInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Initializes the array of items.
void UItemInventoryComponent::InitializeArray(int aMaxSize)
{
	// Error-Checking for negative numbers of aMaxSize:
	if (aMaxSize < 0)
	{
		return;
	}

	// Sets the variable of MyMaxSize to the newly given aMaxSize as this will be ultimately changing the size of this array.
	MyMaxSize = aMaxSize;

	// Sets the given size of the item array:
	MyItems.SetNum(aMaxSize);
	
	// Ensuring each entry is set to NULL:
	for(int i = 0; i < MyItems.Num(); i++)
	{
		MyItems[i] = NULL;
	}
}

// Returns the value of MyMaxSize:
int UItemInventoryComponent::GetMaxSize() const
{
	return MyMaxSize;
}

// Returns the number of items (non-NULL) within the inventory array.
int UItemInventoryComponent::CountItems() const
{
	int ItemCounter{ 0 };
	for (const auto Item : MyItems)
	{
		if (Item)
		{
			ItemCounter++;
		}
	}
	return ItemCounter;
}

// Returns whether or not there is a valid item at the given index within the inventory array.
bool UItemInventoryComponent::ContainsItemAtIndex(int anIndex) const
{
	return IsValid(MyItems[anIndex]);

	// Alternative Method #1:
	/*if (MyItems[anIndex])
	{
		return true;
	}
	return false;*/

	// Alternative Method #2:
	//return MyItems[anIndex] ? true : false;
}

// Iterates through the inventory array starting from the last element. Finds the first empty/NULL entry and places the given Item at that index.
// Returns whether or not the item was added successfully.
bool UItemInventoryComponent::AddItem(UItem* aNewItem)
{
	for(int i = MyItems.Num() - 1; i  >= 0; i--)
	{
		if (!MyItems[i])
		{
			MyItems[i] = aNewItem;
			return true;
		}
	}
	return false;
}

// Checks first to see whether or not the given index is valid.
// If the index is valid, adds the item to the that index within the inventory array. The item is only added if the given index is empty/NULL.
// Returns whether or not the item was added successfully:
bool UItemInventoryComponent::AddItemAtIndex(int anIndex, UItem* aNewItem)
{
	// Check to see if the index given is valid:
	if (anIndex < 0 || anIndex > MyItems.Num() - 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid index of %i given to AddItemAtIndex member function."), anIndex);
		return false;
	}

	// Add the item at the specified index if it's empty/NULL.
	if (!MyItems[anIndex])
	{
		MyItems[anIndex] = aNewItem;
		return true;
	}
	return false;
}

// Checks first to see whether or not the given index is valid.
// If a valid index is given, returns the item at that index.
UItem* UItemInventoryComponent::GetItemAtIndex(int anIndex) const
{
	// Check to see if the index given is valid:
	if (anIndex < 0 || anIndex > MyItems.Num() - 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid index of %i given to GetItemAtIndex member function."), anIndex);
		return NULL;
	}

	// Returns the item at the given index if it's valid:
	if(MyItems[anIndex])
	{
		return MyItems[anIndex];
	}
	// Otherwise return NULL:
	return NULL;
}

// Checks first to see whether or not the given index is valid.
// If a valid index is given, replaces the item at that index with a given item.
// Returns a referenc to the item that has been replaced:
UItem* UItemInventoryComponent::ReplaceItem(int anIndex, UItem* aNewItem)
{
	// Check to see if the index given is valid:
	if (anIndex < 0 || anIndex > MyItems.Num() - 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid index of %i given to ReplaceItem member function."), anIndex);
		return NULL;
	}

	// Storing the previous item reference:
	UItem* CurrentItemReference = MyItems[anIndex];

	// Replace the current item with the new item at the specified index:
	MyItems[anIndex] = aNewItem;

	return CurrentItemReference;
}

// Checks first to see whether or not the given index is valid.
// If a valid index is given, removes the item from the collection.
// Returns a reference to the removed item:
UItem* UItemInventoryComponent::RemoveItem(int anIndex)
{
	// Check to see if the index given is valid:
	if (anIndex < 0 || anIndex > MyItems.Num() - 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid index of %i given to RemoveItem member function."), anIndex);
		return NULL;
	}

	// Storing the previous item reference:
	UItem* CurrentItemReference = MyItems[anIndex];

	// Sets the current entry at the given entry to NULL (essentially removing it but keeping the empty slot):
	MyItems[anIndex] = NULL;

	return CurrentItemReference;

}

// Iterates through the Inventory to find any valid item. If that valid item is the same as the given item to compare to, return the index.
// Otherwise, if the item is not found, returns -1:
int UItemInventoryComponent::ContainsItem(UItem* anItem)
{
	for (int index = 0; index < MyItems.Num(); index++)
	{
		if (MyItems[index])
		{
			if (MyItems[index]->CompareItem(MyItems[index], anItem))
			{
				return index;
			}
		}
	}
	return -1;
}

// Removes the specified item at the given index (if the item exists).
// Returns a reference to the deleted item:
UItem* UItemInventoryComponent::DropItem(UItem* anItem)
{
	return RemoveItem(ContainsItem(anItem));
}

// Sorts TArray Items by their Attack Value (Highest to Lowest):
void UItemInventoryComponent::SortByAttack()
{
	for (int i = 0; i < MyItems.Num(); i++)
	{
		for (int j = i + 1; j < MyItems.Num(); j++)
		{
			// Checking for NULL entry in the item slot we're comparing against:
			if (!MyItems[j])
			{
				continue;
			}

			// Checking for NULL entry in the current item slot we're sorting for:
			if (!MyItems[i])
			{
				// Store the empty item we are using for comparison:
				UItem* TemporaryItemRef = MyItems[i];

				// Replaces our current item slot with the item we've compared to (not NULL):
				MyItems[i] = MyItems[j];

				// Replaces the item held in this slot with our current item (NULL):
				MyItems[j] = TemporaryItemRef;

				continue;
			}


			if (MyItems[i]->GetAttackValue() < MyItems[j]->GetAttackValue())
			{
				// Store current item we are using for comparison:
				UItem* TemporaryItemRef = MyItems[i];

				// Replaces our current item slot with the item we've compared to (has more Attack):
				MyItems[i] = MyItems[j];

				// Replaces the item held in this slot with our current item (which has less Attack):
				MyItems[j] = TemporaryItemRef;
			}
		}
	}
}

// Sorts TArray Items by their Defence Value (Highest to Lowest):
void UItemInventoryComponent::SortByDefence()
{
	for (int i = 0; i < MyItems.Num(); i++)
	{
		for (int j = i + 1; j < MyItems.Num(); j++)
		{
			// Checking for NULL entry in the item slot we're comparing against:
			if (!MyItems[j])
			{
				continue;
			}

			// Checking for NULL entry in the current item slot we're sorting for:
			if (!MyItems[i])
			{
				// Store the empty item we are using for comparison:
				UItem* TemporaryItemRef = MyItems[i];

				// Replaces our current item slot with the item we've compared to (not NULL):
				MyItems[i] = MyItems[j];

				// Replaces the item held in this slot with our current item (NULL):
				MyItems[j] = TemporaryItemRef;

				continue;
			}


			if (MyItems[i]->GetDefenceValue() < MyItems[j]->GetDefenceValue())
			{
				// Store current item we are using for comparison:
				UItem* TemporaryItemRef = MyItems[i];

				// Replaces our current item slot with the item we've compared to (has more Defence):
				MyItems[i] = MyItems[j];

				// Replaces the item held in this slot with our current item (which has less Defence):
				MyItems[j] = TemporaryItemRef;
			}
		}
	}
}

// Sorts the TArray by the Item's name (in alphabetical order):
void UItemInventoryComponent::SortByName()
{
	for (int i = 0; i < MyItems.Num(); i++)
	{
		for (int j = i + 1; j < MyItems.Num(); j++)
		{
			// Checking for NULL entry in the item slot we're comparing against:
			if (!MyItems[j])
			{
				continue;
			}

			// Checking for NULL entry in the current item slot we're sorting for:
			if (!MyItems[i])
			{
				// Store the empty item we are using for comparison:
				UItem* TemporaryItemRef = MyItems[i];

				// Replaces our current item slot with the item we've compared to (not NULL):
				MyItems[i] = MyItems[j];

				// Replaces the item held in this slot with our current item (NULL):
				MyItems[j] = TemporaryItemRef;

				continue;
			}

			// Storing the result of comparing both Item names [string1.Compare(string2)]:
			// Returns -1 string2 is alphabetically before string1.
			// Returns 0 if both strings are equal.
			// Returns 1 if string2 is alphabetically after string1.
			const int StringCompareResult = MyItems[i]->GetName().ToString().Compare(MyItems[j]->GetName().ToString());

			if (StringCompareResult > 0)
			{
				// Store current item we are using for comparison:
				UItem* TemporaryItemRef = MyItems[i];

				// Replaces our current item slot with the item we've compared to (first letter of name is before):
				MyItems[i] = MyItems[j];

				// Replaces the item held in this slot with our current item (first letter of name comes after):
				MyItems[j] = TemporaryItemRef;
			}
		}
	}
}
