// The StoryBeat class is the basis for objects that represent a single conversation point.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "Engine/DataAsset.h"
#include "StoryBeat.generated.h"

/**
 * 
 */
UCLASS()
class COMP5015PROGRAMMING3_API UStoryBeat : public UDataAsset
{
	GENERATED_BODY()

	FName MySpeakerName; // the name of the character speaking.
	FText MyTextContent; // the dialogue to display.
	UPaperSprite* MyCharacterPortrait; // the image of the character to display.
	
};
