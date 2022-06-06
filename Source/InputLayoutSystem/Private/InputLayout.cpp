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
	for (UInputMappingContext* InputMappingContext : TObjectRange<UInputMappingContext>())
	{
		InputMappingContexts.Add(FInputLayoutMappings(InputMappingContext));
	}
}

