// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemInventoryComponent.h"
#include "TestingDebugOutputAssignment3.h"

#include "Ability.h"

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

	UTestingDebugOutputAssignment3* Debugger = NewObject<UTestingDebugOutputAssignment3>();

	Debugger->OutputDebugTestLogs();
	  //---- Testing ----
	// Creating a dummy item to be placed within the inventory:
	//UItem* MyWizardStaff = NewObject<UItem>();
	//UItem* MyWizardStaff2 = NewObject<UItem>();
	//bool bIsEqual = MyWizardStaff->CompareItem(MyWizardStaff, MyWizardStaff2);
	//UE_LOG(LogTemp, Warning, TEXT("%i"), bIsEqual);
	//MyWizardStaff->Initialize("Wizard Staff", 3, 1);
	//bIsEqual = MyWizardStaff->CompareItem(MyWizardStaff, MyWizardStaff2);
	//UE_LOG(LogTemp, Warning, TEXT("%i"), bIsEqual);


	//// Initializing array and adding in the dummy item:
	//InitializeArray(MyMaxSize);

	//MyItems[9] = MyWizardStaff;

	//UE_LOG(LogTemp, Warning, TEXT("Added Item? %i"), AddItemAtIndex(40, MyWizardStaff2));
	//UE_LOG(LogTemp, Warning, TEXT("Added Item? %i"), AddItemAtIndex(8, MyWizardStaff2));
	//UE_LOG(LogTemp, Warning, TEXT("Added Item? %i"), AddItemAtIndex(-1, MyWizardStaff2));
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

// Adds an item to the given index within the inventory array. The item is only added if the specified index is empty/NULL.
// Returns whether or not the item was added successfully.
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

// Retrieves an item at the given index.
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

// Replaces the item at a given index with a given item. Returns a reference to the replaced item.
UItem* UItemInventoryComponent::ReplaceItem(int anIndex, UItem* aNewItem)
{
	// Check to see if the index given is valid:
	if (anIndex < 0 || anIndex > MyItems.Num() - 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid index of %i given to GetItemAtIndex member function."), anIndex);
		return NULL;
	}

	// Storing the previous item reference:
	UItem* CurrentItemReference = MyItems[anIndex];

	// Replace the current item with the new item at the specified index:
	MyItems[anIndex] = aNewItem;

	return CurrentItemReference;
}
