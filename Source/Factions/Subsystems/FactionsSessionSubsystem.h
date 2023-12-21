// Developed by the Factions community

#pragma once

#include "CoreMinimal.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "Factions/PlayerStates/MasterPlayerState.h"

#include "FactionsSessionSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(FactionsSessionLog, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerUpdateDelegate, AMasterPlayerState*, PlayerState);

/**
 * 
 */
UCLASS()
class FACTIONS_API UFactionsSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/**
	* Adds a new player state to the session
	* @param AddedPlayerState The player state to add to the subsystem
	*/
	UFUNCTION()
	void AddSessionPlayerState(AMasterPlayerState* AddedPlayerState);

	/**
	* Removes player state from the session
	* @param RemovedPlayerState Player state to remove from the subsystem
	*/
	UFUNCTION()
	void RemoveSessionPlayerState(AMasterPlayerState* RemovedPlayerState);

	/**
	* Player states currently on the session
	*/
	UPROPERTY(BlueprintReadOnly, Category = "Factions Session")
	TArray<AMasterPlayerState*> SessionPlayerStates;

	/**
	* Player added event, can be used to update lobby player lists automatically
	*/
	UPROPERTY(BlueprintAssignable, Category = "Factions Session")
	FOnPlayerUpdateDelegate OnPlayerAdded;

	/**
	* Player removed event, cab be used to update lobby player lists automatically
	*/
	UPROPERTY(BlueprintAssignable, Category = "Factions Session")
	FOnPlayerUpdateDelegate OnPlayerRemoved;
};