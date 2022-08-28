#include "InputActionCollectionDetails.h"
#include "InputActionCollection.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"


void FInputActionCollectionDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TSharedRef<IPropertyHandle> InputActionsProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UInputActionCollection, InputActions));
	TSharedRef<IPropertyHandle> AvailableActionsProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UInputActionCollection, AvailableActions));

	InputActionsProperty->MarkHiddenByCustomization();
	AvailableActionsProperty->MarkHiddenByCustomization();

	TSharedPtr<IPropertyHandleArray> AvailableActionsPropertyArray = AvailableActionsProperty->AsArray();
	TSharedPtr<IPropertyHandleArray> InputActionsPropertyArray = InputActionsProperty->AsArray();

	check(AvailableActionsPropertyArray);
	check(InputActionsPropertyArray);

	uint32 AvailableActionsNum;
	AvailableActionsPropertyArray->GetNumElements(AvailableActionsNum);

	uint32 InputActionsNum;
	InputActionsPropertyArray->GetNumElements(InputActionsNum);

	if (InputActionsNum != AvailableActionsNum)
	{
		InputActionsPropertyArray->EmptyArray();
		for (uint32 i = 0; i < AvailableActionsNum; ++i)
		{
			InputActionsPropertyArray->AddItem();
		}
	}

	for (uint32 i = 0; i < AvailableActionsNum; ++i)
	{
		FDetailWidgetRow& Row = DetailBuilder.AddCustomRowToCategory(InputActionsProperty, INVTEXT("Input actions"));
		TSharedRef<IPropertyHandle> ElementHandle = AvailableActionsPropertyArray->GetElement(i);
		if(!ElementHandle->IsValidHandle()) {continue;}
		FString ElementValue;
		ElementHandle->GetValue(ElementValue);
		Row.NameContent()
		[
			SNew(STextBlock)
			.Text(FText::FromString(ElementValue))
		]
		.ValueContent()
		[
			InputActionsPropertyArray->GetElement(i)->CreatePropertyValueWidget()
		];
	}
}