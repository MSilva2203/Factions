// Developed by the Factions community


#include "Factions/Interfaces/FactionsEntityInterface.h"

// Add default functionality here for any IFactionsEntityInterface functions that are not pure virtual.

EFactionsTeam IFactionsEntityInterface::GetEntityTeam()
{
	return EFactionsTeam::None;
}
