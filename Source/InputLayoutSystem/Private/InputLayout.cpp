//Copyright JosaiProduction. All rights Reserved.
#include "InputLayout.h"
#include "InputMappingContext.h"

FInputLayoutMappings::FInputLayoutMappings()
	:InputMappingContext(nullptr)
	, InputRemapping() {}

FInputLayoutMappings::FInputLayoutMappings(UInputMappingContext* InputMappingContext)
	:InputMappingContext(InputMappingContext)
	, InputRemapping()
{
	for (const FEnhancedActionKeyMapping& Mapping : InputMappingContext->GetMappings())
	{
		InputRemapping.Add(Mapping.Action);
	}
}

UInputLayout::UInputLayout()
{
	for (UInputMappingContext* InputMappingContext : TObjectRange<UInputMappingContext>(EObjectFlags::RF_NoFlags))
	{
		InputMappingContexts.Add(FInputLayoutMappings(InputMappingContext));
	}
}

