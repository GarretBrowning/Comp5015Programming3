// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Paper2D/Classes/PaperSprite.h"

//UItem::UItem()
//{
//}

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
	// Debugging:
	//UE_LOG(LogTemp, Warning, TEXT("Name: %s."), MyName);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, MyName.ToString());

	return MyName;
}

UPaperSprite* UItem::GetIconImage()
{
	return nullptr;
}

// Returns an FString containing a brief description of the item's basic stats/traits:
FString UItem::ToString()
{
	return "Name: " + MyName.ToString() + " || Attack: " + FString::FromInt(MyAttackValue) + " || Defence: " + FString::FromInt(MyDefenceValue);

	// Alternative solution:
	//return FString::Printf(TEXT("Name: %s || Attack: %i || Defence: %i"), *MyName.ToString(), MyAttackValue, MyDefenceValue);
}
