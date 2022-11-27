// This class component attaches to any NPC to facilitate dialogue interaction.

#pragma once

#include "CoreMinimal.h"
#include "StoryBeat.h"
#include "Components/ActorComponent.h"
#include "StoryBeatTalker.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMP5015PROGRAMMING3_API UStoryBeatTalker : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "StoryBeat")
	bool bContinueDialogue{false};

public:	
	// Sets default values for this component's properties
	UStoryBeatTalker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Stored reference to the original StoryBeat:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "StoryBeat", meta = (AllowPrivateAccess = "true"))
	UStoryBeat* OriginalStoryBeat;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "StoryBeat", meta = (AllowPrivateAccess = "true"))
	UStoryBeat* CurrentStoryBeat;

	// Checks to see if the StoryBeat is connected to another StoryBeat to advance the dialogue.
	// Called when the player interacts with an NPC.
	// Returns a bool whether or not the dialogue is finished.
	UFUNCTION(BlueprintCallable)
	bool AdvanceDialogue(UStoryBeat* aStoryBeat);

	// Sets the value of CurrentStoryBeat to OriginalStoryBeat.
	UFUNCTION(BlueprintCallable)
	void ResetDialogue();
};
