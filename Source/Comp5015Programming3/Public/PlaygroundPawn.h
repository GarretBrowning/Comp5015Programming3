// This is the player pawn used for the playground level for use within Assignments 2-4 (Programming).

#pragma once

#include "CoreMinimal.h"
#include "GenericAbilityComponent.h"
#include "HealthComponent.h"
#include "ItemInventoryComponent.h"
#include "StoryBeatTalker.h"
#include "GameFramework/Pawn.h"
#include "PlaygroundPawn.generated.h"

UCLASS()
class COMP5015PROGRAMMING3_API APlaygroundPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlaygroundPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly)
	UGenericAbilityComponent* GenericAbility;

	UPROPERTY(BlueprintReadOnly)
	UHealthComponent* Health;

	UPROPERTY(BlueprintReadOnly)
	UItemInventoryComponent* ItemInventory;

	UPROPERTY(BlueprintReadOnly)
	UStoryBeatTalker* Dialogue;
};
