#include "AbilityComponent.h"
#include "HealthComponent.h"

// Sets default values for this component's properties
UAbilityComponent::UAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...

	// Setting Reference to Health Component
	const AActor* Owner = GetOwner();
	TargetUnit = Owner->FindComponentByClass<UHealthComponent>();
}

// Called every frame
void UAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Checks the validity of the target and whether we have the damage ability ready and active.
// If the target is still alive, damage them through their health component by `DamageDealt` (25) amount.
void UAbilityComponent::DamageUnit()
{
	if (!TargetUnit)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Target Found."));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("No Target Found."));
		return;
	}

	if (!bHasDamageAbility)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character doesn't have a Damage Ability"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Character doesn't have a Damage Ability"));
		return;
	}

	if (!bDamageCooldownReady)
	{
		UE_LOG(LogTemp, Warning, TEXT("Damage Cooldown is NOT Ready"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Damage Cooldown is NOT Ready"));
		return;
	}

	if (!TargetUnit->IsStillAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't damage a unit that is already dead."));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Can't damage a unit that is already dead."));
		return;
	}

	TargetUnit->TakeDamage(DamageDealt);

	UE_LOG(LogTemp, Warning, TEXT("%s damaged %s for %d damage."), *GetName(), *GetOwner()->GetActorLabel(), DamageDealt);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("%s damaged %s for %d damage."),*GetName(), *GetOwner()->GetActorLabel(), DamageDealt));
}


// Checks the validity of the target and whether we have the heal ability ready and active.
// If the target is still alive, heal them through their health component by `HealAmount` (20) amount.
void UAbilityComponent::HealUnit()
{
	if (!TargetUnit)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Target Found."));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("No Target Found."));
		return;
	}

	if (!bHasHealAbility)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character doesn't have a Healing Ability"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Character doesn't have a Healing Ability"));
		return;
	}

	if (!bHealCooldownReady)
	{
		UE_LOG(LogTemp, Warning, TEXT("Heal Cooldown is NOT Ready"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Heal Cooldown is NOT Ready"));
		return;
	}

	if (!TargetUnit->IsStillAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't heal a unit that is already dead."));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Can't heal a unit that is already dead."));
		return;
	}

	TargetUnit->HealDamage(HealAmount);

	UE_LOG(LogTemp, Warning, TEXT("%s healed %s for %d damage."), *GetName(), *GetOwner()->GetActorLabel(), HealAmount);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("%s healed %s for %d damage."), *GetName(), *GetOwner()->GetActorLabel(), HealAmount));
}


// Checks the validity of the target and whether we have the revive ability ready and active.
// If the target is dead, revive them by the fixed percentage set within the health component (1/3 Max HP).
void UAbilityComponent::ReviveUnit()
{
	if (!TargetUnit)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Target Found."));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("No Target Found."));
		return;
	}

	if (!bHasReviveAbility)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character doesn't have a Revive Ability"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Character doesn't have a Revive Ability"));
		return;
	}

	if (!bReviveCooldownReady)
	{
		UE_LOG(LogTemp, Warning, TEXT("Revive Cooldown is NOT Ready"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Revive Cooldown is NOT Ready"));
		return;
	}

	if (TargetUnit->IsStillAlive())
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't revive a unit that is alive."));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Can't revive a unit that is alive."));
		return;
	}

	TargetUnit->Revive();

	UE_LOG(LogTemp, Warning, TEXT("%s revived %s with %d health."), *GetName(), *GetOwner()->GetActorLabel(), TargetUnit->GetRevivalHealthAmount());
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("%s revived %s with %d health."), *GetName(), *GetOwner()->GetActorLabel(), TargetUnit->GetRevivalHealthAmount()));
}

