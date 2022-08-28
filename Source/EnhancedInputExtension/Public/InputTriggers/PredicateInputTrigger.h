#pragma once
#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "PredicateInputTrigger.generated.h"


UCLASS()
class UPredicateInputTrigger : public UInputTrigger
{
	GENERATED_BODY()

protected:
	virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime);
};