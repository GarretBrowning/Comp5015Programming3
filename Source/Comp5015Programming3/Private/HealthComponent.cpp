// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set the CurrentHP = MaxHP if we start as alive; otherwise set it to 0:
	// CurrentHP = bIsAlive ? MaxHP : 0; // (Commented out for now).
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(int DamageAmount)
{
	if (bIsAlive)
	{
		CurrentHP = std::max(CurrentHP - DamageAmount, 0);
		
		
		if (CurrentHP == 0)
		{
			Death();
			return;
		}

		// Debug Messages:
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("%s Took %d Damage but Survived with %d HP remaining."), *DisplayName.ToString(), DamageAmount, CurrentHP));
		UE_LOG(LogTemp, Display, TEXT("%s Took %d Damage but Survived with %d HP remaining."), *DisplayName.ToString(), DamageAmount, CurrentHP);
	}
}

void UHealthComponent::HealDamage(int HealAmount)
{
	if (bIsAlive)
	{
		CurrentHP = std::min(CurrentHP + HealAmount, MaxHP);

		// Debug Messages:
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("%s Healed %d Damage, Currently have %d HP remaining of a Max of %d."), *DisplayName.ToString(), HealAmount, CurrentHP, MaxHP));
		UE_LOG(LogTemp, Display, TEXT("%s Healed %d Damage, Currently have %d HP remaining of a Max of %d."), *DisplayName.ToString(), HealAmount, CurrentHP, MaxHP);
	}
}

bool UHealthComponent::IsStillAlive() const
{
	return bIsAlive;
}

int UHealthComponent::GetRevivalHealthAmount() const
{
	return RevivalHealthAmount;
}

void UHealthComponent::Death()
{
	bIsAlive = false;

	// Debug Messages:
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Black, TEXT("You are dead. DEAD!"));
	UE_LOG(LogTemp, Display, TEXT("You are dead. DEAD!"));
}

void UHealthComponent::Revive()
{
	if (!bIsAlive)
	{
		bIsAlive = true;
		CurrentHP = RevivalHealthAmount;

		// Debug Messages:
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("%s Revived with %d Health."), *DisplayName.ToString(), RevivalHealthAmount));
		UE_LOG(LogTemp, Display, TEXT("%s Revived with %d Health."), *DisplayName.ToString(), RevivalHealthAmount);
	}
}

