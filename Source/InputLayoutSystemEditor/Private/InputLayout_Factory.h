#pragma once
#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "InputLayout_Factory.generated.h"

UCLASS()
class INPUTLAYOUTSYSTEMEDITOR_API UInputLayout_Factory : public UFactory
{
	GENERATED_BODY()
public:
	UInputLayout_Factory(const class FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};