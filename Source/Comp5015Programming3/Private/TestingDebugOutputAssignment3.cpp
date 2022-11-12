// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingDebugOutputAssignment3.h"
#include "Item.h"
#include "ItemInventoryComponent.h"


UTestingDebugOutputAssignment3::UTestingDebugOutputAssignment3()
{};


void UTestingDebugOutputAssignment3::OutputDebugTestLogs()
{
	// -- ITEMS --
	TestItemConstructor();
	TestItemInitialize();
	TestGetAttackValue();
	TestGetDefenceValue();
	TestGetName();
	TestCompareItem();

	// -- ITEM INVENTORY COMPONENT --
	TestInitializeArray();
	TestCountItems();
	TestAddItem();
	TestContainsItemAtIndex();
	TestGetItemAtIndex();
	return;
}

// Outputs the 
void UTestingDebugOutputAssignment3::TestItemConstructor()
{

	UItem* MyTestDefaultItem = NewObject<UItem>();

	UE_LOG(LogTemp, Warning, TEXT("-- Testing Item Constructor --"));
	UE_LOG(LogTemp, Display, TEXT("Default Item Constructor: --- %s"), *MyTestDefaultItem->ToString());
}

void UTestingDebugOutputAssignment3::TestItemInitialize()
{

	UItem* MyTestWizardStaff = NewObject<UItem>();
	MyTestWizardStaff->Initialize("Wizard Staff", 6, 1);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing Item Initialize() --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Test Wizard Staff: --- %s"), *MyTestWizardStaff->ToString());
}

void UTestingDebugOutputAssignment3::TestGetAttackValue()
{

	UItem* MyTestWizardStaff = NewObject<UItem>();
	MyTestWizardStaff->Initialize("Wizard Staff", 6, 1);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing Item GetAttackValue() --"));
	UE_LOG(LogTemp, Display, TEXT("Getting Wizard Staff Attack Value: --- %i"), MyTestWizardStaff->GetAttackValue());
}

void UTestingDebugOutputAssignment3::TestGetDefenceValue()
{

	UItem* MyTestShield = NewObject<UItem>();
	MyTestShield->Initialize("Shield", 1, 4);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing Item GetDefenceValue() --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Test Shield: --- %s"), *MyTestShield->ToString());
	UE_LOG(LogTemp, Display, TEXT("Getting Shield Defence Value: --- %i"), MyTestShield->GetAttackValue());
}

void UTestingDebugOutputAssignment3::TestGetName()
{

	UItem* MyTestShortSword = NewObject<UItem>();
	MyTestShortSword->Initialize("Short Sword", 5, 2);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing Item GetName() --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Short Sword: --- %s"), *MyTestShortSword->ToString());
	UE_LOG(LogTemp, Display, TEXT("Getting Short Sword Name: --- %s"), *MyTestShortSword->GetName().ToString());
}

// There is no Icon member variable contained within the Item class, so I am unsure of how to obtain an icon image if there is no place to store it.
void UTestingDebugOutputAssignment3::TestGetIconImage()
{
}


void UTestingDebugOutputAssignment3::TestCompareItem()
{

	UItem* MyTestShield = NewObject<UItem>();
	MyTestShield->Initialize("Shield", 1, 4);

	UItem* MyTestShortSword = NewObject<UItem>();
	MyTestShortSword->Initialize("Short Sword", 5, 2);

	UItem* MyTestShortSword2 = NewObject<UItem>();
	MyTestShortSword2->Initialize("Short Sword", 5, 2);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing Item CompareItem(UItem* anItem, UItem* anItemToCompare) --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Shield: --- %s"), *MyTestShield->ToString());
	UE_LOG(LogTemp, Display, TEXT("Initializing Short Sword: --- %s"), *MyTestShortSword->ToString());
	UE_LOG(LogTemp, Display, TEXT("Initializing Short Sword (duplicate): --- %s"), *MyTestShortSword2->ToString());
	UE_LOG(LogTemp, Display, TEXT("^Comparing Shield against Short Sword: --- Equal? %s"), MyTestShield->CompareItem(MyTestShield, MyTestShortSword) ? TEXT("True") : TEXT("False"));
	UE_LOG(LogTemp, Display, TEXT("^Comparing Short Sword against Short Sword (duplicate): --- Equal? %s"), MyTestShield->CompareItem(MyTestShortSword, MyTestShortSword2) ? TEXT("True") : TEXT("False"));
}

void UTestingDebugOutputAssignment3::TestInitializeArray()
{
	UItemInventoryComponent* MyTestInventory = NewObject<UItemInventoryComponent>();
	MyTestInventory->InitializeArray(MySmallSize);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing ItemInventoryComponent InitializeArray(int aMaxSize) --"));
	UE_LOG(LogTemp, Display, TEXT("Inventory has been created with a size of: %i"), MyTestInventory->GetMaxSize());
}

void UTestingDebugOutputAssignment3::TestCountItems()
{
	UItem* MyTestShield = NewObject<UItem>();
	MyTestShield->Initialize("Shield", 1, 4);

	UItemInventoryComponent* MyTestInventory = NewObject<UItemInventoryComponent>();
	MyTestInventory->InitializeArray(MySmallSize);

	MyTestInventory->AddItem(MyTestShield);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing ItemInventoryComponent CountItems() --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Shield: --- %s"), *MyTestShield->ToString());
	UE_LOG(LogTemp, Display, TEXT("Inventory has been created with a size of: %i"), MyTestInventory->GetMaxSize());
	UE_LOG(LogTemp, Display, TEXT("Adding Shield to Inventory. Items in Inventory: %i"), MyTestInventory->CountItems());
}

void UTestingDebugOutputAssignment3::TestContainsItemAtIndex()
{
	UItem* MyTestShield = NewObject<UItem>();
	MyTestShield->Initialize("Shield", 1, 4);

	UItemInventoryComponent* MyTestInventory = NewObject<UItemInventoryComponent>();
	MyTestInventory->InitializeArray(MySmallSize);
	MyTestInventory->AddItemAtIndex(0, MyTestShield);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing ItemInventoryComponent ContainsItemAtIndex(int anIndex) --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Shield: --- %s"), *MyTestShield->ToString());
	UE_LOG(LogTemp, Display, TEXT("Inventory has been created with a size of: %i"), MyTestInventory->GetMaxSize());
	UE_LOG(LogTemp, Display, TEXT("Adding Shield to the First Inventory Slot [0]."));
	UE_LOG(LogTemp, Display, TEXT("Checking if 'Shield' is in Slot [0]: --- Found? %s"), MyTestInventory->ContainsItemAtIndex(0) ? TEXT("True") : TEXT("False"));
}

void UTestingDebugOutputAssignment3::TestAddItem()
{
	UItem* MyTestShield = NewObject<UItem>();
	MyTestShield->Initialize("Shield", 1, 4);

	UItemInventoryComponent* MyTestInventory = NewObject<UItemInventoryComponent>();
	MyTestInventory->InitializeArray(MySmallSize);

	MyTestInventory->AddItem(MyTestShield);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing ItemInventoryComponent AddItem(UItem* aNewItem) --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Shield: --- %s"), *MyTestShield->ToString());
	UE_LOG(LogTemp, Display, TEXT("Inventory has been created with a size of: %i"), MyTestInventory->GetMaxSize());
	if (MyTestInventory->ContainsItemAtIndex(MySmallSize - 1))
	{
		UE_LOG(LogTemp, Display, TEXT("Item Successfully Added to Inventory."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Adding Item to Inventory Failed."));
	}
}

void UTestingDebugOutputAssignment3::TestAddItemAtIndex()
{
	UItem* MyTestShortSword = NewObject<UItem>();
	MyTestShortSword->Initialize("Short Sword", 5, 2);

	UItemInventoryComponent* MyTestInventory = NewObject<UItemInventoryComponent>();
	MyTestInventory->InitializeArray(MySmallSize);
	MyTestInventory->AddItemAtIndex(0, MyTestShortSword);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing ItemInventoryComponent TestAddItemAtIndex(int anIndex, UItem* anItem) --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Short Sword: --- %s"), *MyTestShortSword->ToString());
	UE_LOG(LogTemp, Display, TEXT("Inventory has been created with a size of: %i"), MyTestInventory->GetMaxSize());
	UE_LOG(LogTemp, Display, TEXT("Adding Short Sword to the Third Inventory Slot [2] using AddItemAtIndex method."));
	UE_LOG(LogTemp, Display, TEXT("Checking if 'Short Sword' is in Slot [2]: --- Found? %s"), MyTestInventory->ContainsItemAtIndex(2) ? TEXT("True") : TEXT("False"));
}

void UTestingDebugOutputAssignment3::TestGetItemAtIndex()
{

	UItem* MyTestWizardStaff = NewObject<UItem>();
	MyTestWizardStaff->Initialize("Wizard Staff", 6, 1);

	UItemInventoryComponent* MyTestInventory = NewObject<UItemInventoryComponent>();
	MyTestInventory->InitializeArray(MySmallSize);
	MyTestInventory->AddItemAtIndex(1, MyTestWizardStaff);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing ItemInventoryComponent GetItemAtIndex(int anIndex)  --"));
	UE_LOG(LogTemp, Display, TEXT("Initializing Test Wizard Staff: --- %s"), *MyTestWizardStaff->ToString());
	UE_LOG(LogTemp, Display, TEXT("Inventory has been created with a size of: %i"), MyTestInventory->GetMaxSize());
	UE_LOG(LogTemp, Display, TEXT("Adding Wizard Staff to the Second Inventory Slot [1] using AddItemAtIndex method."));
	UE_LOG(LogTemp, Display, TEXT("Retrieving item using the GetItemAtIndex method."));

	if (MyTestInventory->GetItemAtIndex(1))
	{
		UE_LOG(LogTemp, Display, TEXT("Item contained at Inventory Slot [1]: %s"), *MyTestInventory->GetItemAtIndex(1)->ToString());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Item could not be retrieved from specified index."));
	}


}
