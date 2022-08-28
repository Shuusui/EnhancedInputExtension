#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputActionCollection.generated.h"

class UInputAction;

UCLASS(Abstract, BlueprintType, Blueprintable)
class ENHANCEDINPUTEXTENSION_API UInputActionCollection : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TArray<UInputAction*> InputActions;

#if WITH_EDITORONLY_DATA
	/**
	 * Set Input action names in the same order you would extract them out of the InputActions array. They will
	 * get automatically shown in editor to set the right input action at the right index. This will also initialize
	 * the "InputActions" array to the amount of elements in the "AvailableActions" array.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	TArray<FString> AvailableActions;
#endif
};
