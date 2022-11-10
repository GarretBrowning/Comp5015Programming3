// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Paper2D/Classes/PaperSprite.h"

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

// Returns an FString containing a brief description of the item's basic stats/traits on-screen and to the log (debugging).
FString UItem::ToString()
{
	FString myDescription;



	UE_LOG(LogTemp, Warning, TEXT("Generic Ability Activated"));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Generic Ability Activated"));

	return myDescription;
}
