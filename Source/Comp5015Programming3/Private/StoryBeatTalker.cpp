#include "StoryBeatTalker.h"

// Sets default values for this component's properties
UStoryBeatTalker::UStoryBeatTalker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Sets a reference to the original StoryBeat set:
	OriginalStoryBeat = CurrentStoryBeat;
	// ...
}

// Called when the game starts
void UStoryBeatTalker::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UStoryBeatTalker::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Checks to see if the StoryBeat is connected to another StoryBeat to advance the dialogue.
// Called when the player interacts with an NPC.
// Returns a bool whether or not the dialogue is finished.
bool UStoryBeatTalker::AdvanceDialogue(UStoryBeat* aStoryBeat)
{

	bContinueDialogue = false;
	if (aStoryBeat->NextStoryBeat)
	{
		CurrentStoryBeat = aStoryBeat->NextStoryBeat;
		bContinueDialogue = true;
	}

	return bContinueDialogue;
}

// Sets the value of CurrentStoryBeat to OriginalStoryBeat.
void UStoryBeatTalker::ResetDialogue()
{
	CurrentStoryBeat = OriginalStoryBeat;
}

