// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInventoryComponent.h"

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

	// Creating a dummy item to be placed within the inventory:
	UItem* MyWizardStaff = NewObject<UItem>();
	UItem* MyWizardStaff2 = NewObject<UItem>();
	bool bIsEqual = MyWizardStaff->CompareItem(MyWizardStaff, MyWizardStaff2);
	UE_LOG(LogTemp, Warning, TEXT("%i"), bIsEqual);
	MyWizardStaff->Initialize("Wizard Staff", 3, 1);
	bIsEqual = MyWizardStaff->CompareItem(MyWizardStaff, MyWizardStaff2);
	UE_LOG(LogTemp, Warning, TEXT("%i"), bIsEqual);



	//UE_LOG(LogTemp, Warning, TEXT("%s"), *MyWizardStaff->ToString());

	// Initializing array and adding in the dummy item:
	InitializeArray(MyMaxSize);
	MyItems[0] = MyWizardStaff;
	MyItems[1] = MyWizardStaff2;
	UE_LOG(LogTemp, Warning, TEXT("Number of items in inventory: %i"), CountItems());
	UE_LOG(LogTemp, Warning, TEXT("Number of inventory slots: %i"), MyItems.Num());
	
	// ...
	
}

// Called every frame
void UItemInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Initializing the array of items:
void UItemInventoryComponent::InitializeArray(int aMaxSize)
{
	// Sets the given size of the item array:
	MyItems.SetNum(aMaxSize);
	// Proof of Items:
	for(int i = 0; i < MyItems.Num(); i++)
	{
		MyItems[i] = NULL;
	}
}

// Returns the number of items (non-NULL) within the inventory array:
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

bool UItemInventoryComponent::AddItemAtIndex(int index, UItem* NewItem)
{
	return true;
}
