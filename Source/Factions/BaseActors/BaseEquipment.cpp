// Developed by the Factions community


#include "Factions/BaseActors/BaseEquipment.h"

// Sets default values
ABaseEquipment::ABaseEquipment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ABaseEquipment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseEquipment::Equip()
{
	if (GetOwner() == GetWorld()->GetFirstPlayerController())
	{
		EnableInput(GetWorld()->GetFirstPlayerController());
	}

	OnEquipped();
}

void ABaseEquipment::Unequip()
{
	DisableInput(GetWorld()->GetFirstPlayerController());

	OnUnequipped();
}

