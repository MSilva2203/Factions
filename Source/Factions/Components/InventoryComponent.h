// Developed by the Factions community

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Factions/Data/EquipmentData.h"

#include "InventoryComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectionUpdatedDelegate, const int32, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthKitUpdatedDelegate, ABaseEquipment*, Equipment);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExplosiveUpdatedDelegate, ABaseEquipment*, Equipment);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFireBombUpdatedDelegate, ABaseEquipment*, Equipment);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSupportBombUpdatedDelegate, ABaseEquipment*, Equipment);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShortWeaponUpdatedDelegate, ABaseEquipment*, Equipment);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLargeWeaponUpdatedDelegate, ABaseEquipment*, Equipment);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FACTIONS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void SetupInventory();

	UFUNCTION()
	void ResetInventory();

	UFUNCTION()
	void ResetWeapons();

	UFUNCTION()
	void SetOwningCharacter(ACharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetSelection(const int32 NewValue);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void OffsetVerticalSelection(const int32 Offset);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void OffsetHorizontalSelection(const int32 Offset);

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetSelection() const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	ABaseEquipment* GetSelectionEquipment(const int32 Value);

	UFUNCTION(BlueprintPure, Category = "Inventory")
	ABaseEquipment* GetCurrentEquipment();

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool IsWeaponEquipped() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	FInventoryVerticalEquipment VerticalEquipmentData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	FInventoryHorizontalEquipment HorizontalEquipmentData;

	UPROPERTY(ReplicatedUsing = "OnRep_Selection", BlueprintReadOnly, Category = "Inventory")
	int32 Selection;

	UPROPERTY(ReplicatedUsing = "OnRep_HealthKit", BlueprintReadOnly, Category = "Inventory")
	ABaseEquipment* HealthKit;

	UPROPERTY(ReplicatedUsing = "OnRep_ExplosiveBomb", BlueprintReadOnly, Category = "Inventory")
	ABaseEquipment* ExplosiveBomb;;

	UPROPERTY(ReplicatedUsing = "OnRep_FireBomb", BlueprintReadOnly, Category = "Inventory")
	ABaseEquipment* FireBomb;

	UPROPERTY(ReplicatedUsing = "OnRep_SupportBomb", BlueprintReadOnly, Category = "Inventory")
	ABaseEquipment* SupportBomb;

	UPROPERTY(ReplicatedUsing = "OnRep_ShortWeapon", BlueprintReadOnly, Category = "Inventory")
	ABaseEquipment* ShortWeapon;

	UPROPERTY(ReplicatedUsing = "OnRep_LargeWeapon", BlueprintReadOnly, Category = "Inventory")
	ABaseEquipment* LargeWeapon;
	
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnSelectionUpdatedDelegate OnSelectionUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnHealthKitUpdatedDelegate OnHealthKitUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnExplosiveUpdatedDelegate OnExplosiveUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnFireBombUpdatedDelegate OnFireBombUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnSupportBombUpdatedDelegate OnSupportBombUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnShortWeaponUpdatedDelegate OnShortWeaponUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnLargeWeaponUpdatedDelegate OnLargeWeaponUpdated;

protected:
	UFUNCTION()
	virtual void OnRep_Selection();

	UFUNCTION()
	virtual void OnRep_HealthKit();

	UFUNCTION()
	virtual void OnRep_ExplosiveBomb();

	UFUNCTION()
	virtual void OnRep_FireBomb();

	UFUNCTION()
	virtual void OnRep_SupportBomb();

	UFUNCTION()
	virtual void OnRep_ShortWeapon();

	UFUNCTION()
	virtual void OnRep_LargeWeapon();

	UFUNCTION(Server, Unreliable, WithValidation)
	void Server_SetSelection(const int32 NewValue);
	void Server_SetSelection_Implementation(const int32 NewValue);
	bool Server_SetSelection_Validate(const int32 NewValue);

	UPROPERTY()
	int32 PreviousSelection;

};
