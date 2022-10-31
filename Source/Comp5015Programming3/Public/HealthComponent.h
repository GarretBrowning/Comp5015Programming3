// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"



UCLASS( BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMP5015PROGRAMMING3_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	// EditDefaultsOnly set for properties to be able to change values within the Editor but not for instances during runtime.

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default Unit Values", meta = (AllowPrivateAccess = "true"))
	int MaxHP = 100; // Arbitrary Value.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default Unit Values", meta = (AllowPrivateAccess = "true"))
	bool bIsAlive = true; // Alive is default.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default Unit Values", meta = (AllowPrivateAccess = "true"))
	int RevivalHealthAmount = MaxHP/3; // Starting With Arbitrary Value of 1/3 of MaxHP.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default Unit Values", meta = (AllowPrivateAccess = "true"))
	int CurrentHP = MaxHP; // Start with MaxHP amount of HP.
	FName DisplayName = this->GetClass()->GetFName();

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int DamageAmount);

	UFUNCTION(BlueprintCallable)
	void HealDamage(int HealAmount);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsStillAlive() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetRevivalHealthAmount() const;

	UFUNCTION(BlueprintCallable)
	void Death();

	UFUNCTION(BlueprintCallable)
	void Revive();

};
