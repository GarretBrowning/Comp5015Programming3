// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingDebugOutputAssignment3.h"
#include "Item.h"


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
	UE_LOG(LogTemp, Display, TEXT("Initizializing Test Wizard Staff: --- %s"), *MyTestWizardStaff->ToString());
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
	UE_LOG(LogTemp, Display, TEXT("Initizializing Test Shield: --- %s"), *MyTestShield->ToString());
	UE_LOG(LogTemp, Display, TEXT("Getting Shield Defence Value: --- %i"), MyTestShield->GetAttackValue());
}

void UTestingDebugOutputAssignment3::TestGetName()
{

	UItem* MyTestShortSword = NewObject<UItem>();
	MyTestShortSword->Initialize("Short Sword", 5, 2);

	UE_LOG(LogTemp, Warning, TEXT("-- Testing Item GetName() --"));
	UE_LOG(LogTemp, Display, TEXT("Initizializing Short Sword: --- %s"), *MyTestShortSword->ToString());
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
	UE_LOG(LogTemp, Display, TEXT("Initizializing Shield: --- %s"), *MyTestShield->ToString());
	UE_LOG(LogTemp, Display, TEXT("Initizializing Short Sword: --- %s"), *MyTestShortSword->ToString());
	UE_LOG(LogTemp, Display, TEXT("Initizializing Short Sword (duplicate): --- %s"), *MyTestShortSword2->ToString());
	UE_LOG(LogTemp, Display, TEXT("^Comparing Shield against Short Sword: --- Equal? %s"), MyTestShield->CompareItem(MyTestShield, MyTestShortSword) ? TEXT("True") : TEXT("False"));
	UE_LOG(LogTemp, Display, TEXT("^Comparing Short Sword against Short Sword (duplicate): --- Equal? %s"), MyTestShield->CompareItem(MyTestShortSword, MyTestShortSword2) ? TEXT("True") : TEXT("False"));
}
