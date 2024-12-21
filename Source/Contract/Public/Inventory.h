#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Inventory.generated.h"

// Forward declaration for BP_WeaponMaster
class ABP_WeaponMaster;

UCLASS(Blueprintable, BlueprintType)
class CONTRACT_API AInventory : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AInventory();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Adds an item to the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(ABP_WeaponMaster* Item);

	// Removes an item from the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(ABP_WeaponMaster* Item);

	// Gets all items in the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	const TArray<ABP_WeaponMaster*>& GetInventoryItems() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// The maximum size of the inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	int32 MaxInventorySize;

	// Array to store inventory items
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<ABP_WeaponMaster*> InventoryItems;
};
