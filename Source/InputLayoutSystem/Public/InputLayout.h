#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputLayout.generated.h"

class UInputMappingContext;
class UInputAction;


USTRUCT(BlueprintType)
struct FInputLayoutMappings
{
	GENERATED_BODY()

	FInputLayoutMappings();

	FInputLayoutMappings(UInputMappingContext* InputMappingContext);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mappings")
	UInputMappingContext* InputMappingContext;

	UPROPERTY()
	TMap<const UInputAction*, FKey> InputRemapping;
};

UCLASS(BlueprintType, Config = Input)
class INPUTLAYOUTSYSTEM_API UInputLayout : public UDataAsset
{
	GENERATED_BODY()

public:
	UInputLayout();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mappings")
	TArray<FInputLayoutMappings> InputMappingContexts;

};