// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Paper2D/Classes/PaperSprite.h"


// Default Constructor with no base traits given:
UItem::UItem()
{
	Initialize();
}

// Initializes the base properties of the item using the given parameter values:
void UItem::Initialize(FName aName, int anAttackValue, int aDefenceValue)
{
	MyName = aName;
	MyAttackValue = anAttackValue;
	MyDefenceValue = aDefenceValue;
}

// Returns the Item's Attack Value:
int UItem::GetAttackValue()
{
	return MyAttackValue;
}

// Returns the Item's Defence Value:
int UItem::GetDefenceValue()
{
	return MyDefenceValue;
}

// Returns the Item's Name:
FName UItem::GetName()
{
	return MyName;
}

// Returns a nullptr (no class member to hold a UPaperSprite object).
UPaperSprite* UItem::GetIconImage()
{
	return nullptr;
}

// Returns whether or not an Item has equal Name, Attack, and Defence values compared to a given item.
bool UItem::CompareItem(UItem* anItem, UItem* anItemToCompare)
{
	if (
		anItem && anItemToCompare &&
		anItem->GetName() == anItemToCompare->GetName() &&
		anItem->GetAttackValue() == anItemToCompare->GetAttackValue() &&
		anItem->GetDefenceValue() == anItemToCompare->GetDefenceValue()
		)
	{
		UE_LOG(LogTemp, Display, TEXT("Items are the same."));
		return true;
	}
	UE_LOG(LogTemp, Display, TEXT("Items are the not equal."));
	return false;
}

// Returns an FString containing a brief description of the item's basic stats/traits:
FString UItem::ToString()
{
	return "Name: " + MyName.ToString() + " || Attack: " + FString::FromInt(MyAttackValue) + " || Defence: " + FString::FromInt(MyDefenceValue);

	// Alternative solution:
	//return FString::Printf(TEXT("Name: %s || Attack: %i || Defence: %i"), *MyName.ToString(), MyAttackValue, MyDefenceValue);
}
