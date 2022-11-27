#include "PlaygroundPawn.h"

// Sets default values
APlaygroundPawn::APlaygroundPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adding in a generic ability component.
	GenericAbility = CreateDefaultSubobject<UGenericAbilityComponent>(TEXT("Abilities"));

	// Adding in a health component.
	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));

	// Adding in an item inventory component.
	ItemInventory = CreateDefaultSubobject<UItemInventoryComponent>(TEXT("Inventory"));

	// Adding in a story beat talker component (for dialogue system | Assignment 4).
	Dialogue = CreateDefaultSubobject<UStoryBeatTalker>(TEXT("Dialogue"));
}

// Called when the game starts or when spawned
void APlaygroundPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlaygroundPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input	
void APlaygroundPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Binding input to specific abilities:
	//PlayerInputComponent->BindAction("DamageAbility", IE_Pressed, this, &GenericAbility::ActivateAbilityInComponent)
}

