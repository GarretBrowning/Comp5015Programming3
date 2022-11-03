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
