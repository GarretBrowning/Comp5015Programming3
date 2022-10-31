// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericAbilityComponent.h"
#include "HealthComponent.h" // Need to include this for our Health Component reference.
#include "DamageAbility.h" // Needed for our DamageAbility reference.
#include "HealAbility.h" // Needed for our DamageAbility reference.

// Sets default values for this component's properties
UGenericAbilityComponent::UGenericAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGenericAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get the Health Component on this Actor:
	UHealthComponent* HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();
	if (HealthComponent)
	{
		SetTarget(HealthComponent);
	}

	//AbilityToActivate = NewObject<UDamageAbility>();
	AbilityArray.Add(NewObject<UDamageAbility>());
	AbilityArray.Add(NewObject<UHealAbility>());
}


// Called every frame
void UGenericAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// .....
}

/* -- - Shared amongst all Abilities-- - */

// Sets the reference to the target health component:
void UGenericAbilityComponent::SetTarget(UHealthComponent* RefToHealth)
{
	CurrentTarget = RefToHealth;
}

UHealthComponent* UGenericAbilityComponent::GetTarget()
{
	return CurrentTarget;
}

void UGenericAbilityComponent::ActivateAbilityInComponent()
{
	
	

	if (IsValid(AbilityToActivate))
	{
		AbilityToActivate->ActivateAbility();
	}
}

void UGenericAbilityComponent::ActivateAbilityInArray(int id)
{
	if (AbilityArray.Num() > id && id >= 0)
	{
		AbilityArray[id]->ActivateAbility();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("INVALID INDEX CALLED (trying to access AbilityArray"));
	}
}

