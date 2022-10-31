// The Ability Component class can be attached to any actor to help facilitate actions taken against actors with a health component (including self).

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

class UHealthComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMP5015PROGRAMMING3_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

	// Health Component Reference:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "-- Components --", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* TargetUnit;

	// Adjustable Settings:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "-- Adjustable Settings --", meta = (AllowPrivateAccess = "true"))
	int DamageDealt{25};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "-- Adjustable Settings --", meta = (AllowPrivateAccess = "true"))
	int HealAmount{20};

	// Available Actions:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "-- Available Actions --", meta = (AllowPrivateAccess = "true"))
	bool bHasDamageAbility{true};
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "-- Available Actions --", meta = (AllowPrivateAccess = "true"))
	bool bHasHealAbility{true};
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "-- Available Actions --", meta = (AllowPrivateAccess = "true"))
	bool bHasReviveAbility{true};

	// Cooldowns:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "-- Cooldowns --", meta = (AllowPrivateAccess = "true"))
	bool bDamageCooldownReady{true};
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "-- Cooldowns --", meta = (AllowPrivateAccess = "true"))
	bool bHealCooldownReady{true};
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "-- Cooldowns --", meta = (AllowPrivateAccess = "true"))
	bool bReviveCooldownReady{true};

public:	
	// Sets default values for this component's properties
	UAbilityComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Damage the unit by a set amount (25)
	UFUNCTION(BlueprintCallable)
	void DamageUnit();

	// Heal the unit by a set amount (20)
	UFUNCTION(BlueprintCallable)
	void HealUnit();

	// Revive the unit by a set percentage of their max HP (1/3)
	UFUNCTION(BlueprintCallable)
	void ReviveUnit();
		
};
