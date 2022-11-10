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

int UItem::GetAttackValue()
{
	return MyAttackValue;
}

int UItem::GetDefenceValue()
{
	return MyDefenceValue;
}

FName UItem::GetName()
{
	return MyName;
}

UPaperSprite* UItem::GetIconImage()
{
	return nullptr;
}

bool UItem::CompareItem(UItem* anItem, UItem* anItemToCompare)
{
	if (
		anItem && anItemToCompare &&
		anItem->GetName() == anItemToCompare->GetName() &&
		anItem->GetAttackValue() == anItemToCompare->GetAttackValue() &&
		anItem->GetDefenceValue() == anItemToCompare->GetDefenceValue()
		)
	{
		UE_LOG(LogTemp, Warning, TEXT("Items are the same."));
		return true;
	}
	UE_LOG(LogTemp, Warning, TEXT("Items are the not equal."));
	return false;
}

// Returns an FString containing a brief description of the item's basic stats/traits:
FString UItem::ToString()
{
	return "Name: " + MyName.ToString() + " || Attack: " + FString::FromInt(MyAttackValue) + " || Defence: " + FString::FromInt(MyDefenceValue);

	// Alternative solution:
	//return FString::Printf(TEXT("Name: %s || Attack: %i || Defence: %i"), *MyName.ToString(), MyAttackValue, MyDefenceValue);
}
