#include "Inventory.h"

// Sets default values
AInventory::AInventory()
{
	// Set the default maximum inventory size
	MaxInventorySize = 10; // You can adjust this value as needed

	// Enable ticking for this actor
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInventory::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AInventory::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Adds an item to the inventory
bool AInventory::AddItem(ABP_WeaponMaster* Item)
{
	if (!Item || InventoryItems.Num() >= MaxInventorySize)
	{
		// Return false if the item is invalid or the inventory is full
		return false;
	}

	InventoryItems.Add(Item);
	return true;
}

// Removes an item from the inventory
bool AInventory::RemoveItem(ABP_WeaponMaster* Item)
{
	if (!Item || !InventoryItems.Contains(Item))
	{
		// Return false if the item is invalid or not in the inventory
		return false;
	}

	InventoryItems.Remove(Item);
	return true;
}

// Gets all items in the inventory
const TArray<ABP_WeaponMaster*>& AInventory::GetInventoryItems() const
{
	return InventoryItems;
}
