#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputActionValue.h"
#include "PredicateObject.generated.h"

class UEnhancedPlayerInput;

UCLASS(BlueprintType, EditInlineNew, Abstract)
class UPredicateObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Input|InputTriggers")
	bool Predicate(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime);
	virtual bool Predicate_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifierValue, float DeltaTime) {return false;}
};