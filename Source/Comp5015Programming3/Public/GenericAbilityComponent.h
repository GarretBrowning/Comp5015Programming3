// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Components/ActorComponent.h"
#include "GenericAbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMP5015PROGRAMMING3_API UGenericAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGenericAbilityComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// The Health Component of the current Target:
	// Forward declaring the class (needs to be above the method I call which uses it).

	UPROPERTY(EditDefaultsOnly)
	class UHealthComponent* CurrentTarget = nullptr; // Pointer (Could also use NULL macro instead of nullptr)

	// Passing a Pointer to the Health Component:
	UFUNCTION(BlueprintCallable, Category = "Ability|Initialization")
	void SetTarget(UHealthComponent* RefToHealth);

	// Get the reference:
	UFUNCTION(BlueprintCallable, Category = "Ability|Accessors")
	UHealthComponent* GetTarget();

	// --- Activate Ability ---
	// The ability to activate:
	UPROPERTY(EditDefaultsOnly, Category = "Ability|Generic")
	UAbility* AbilityToActivate;

	// Activates a generic ability.
	// Named this way to differentiate from the UAbility 'ActivateAbility' method.
	UFUNCTION(BlueprintCallable, Category = "Ability|Generic")
	void ActivateAbilityInComponent();

	// --- Multiple Abilities ---
	UPROPERTY(EditDefaultsOnly, Category = "Ability|Generic")
	TArray<UAbility*> AbilityArray;

	UFUNCTION(BlueprintCallable, Category = "Ability|Generic")
	void ActivateAbilityInArray(int id);
};
