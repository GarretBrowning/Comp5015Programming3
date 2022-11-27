// The StoryBeat class is the basis for objects that represent a single conversation point.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "Engine/DataAsset.h"
#include "StoryBeat.generated.h"

UCLASS()
class COMP5015PROGRAMMING3_API UStoryBeat : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Dialogue", meta = (AllowPrivateAccess = "true"))
	UStoryBeat* NextStoryBeat; // the next StoryBeat for the UI to display.
	 
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Dialogue", meta = (AllowPrivateAccess = "true"))
	FName SpeakerName; // the name of the character speaking.

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Dialogue", meta = (AllowPrivateAccess = "true"))
	FText TextContent; // the dialogue to display.

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Dialogue", meta = (AllowPrivateAccess = "true"))
	UPaperSprite* CharacterPortrait; // the image of the character to display.
	
};
