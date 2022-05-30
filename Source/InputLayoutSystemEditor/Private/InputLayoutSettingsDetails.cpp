#include "InputLayoutSettingsDetails.h"
#include "DetailLayoutBuilder.h"


TSharedRef<IDetailCustomization> FInputLayoutSettingsDetails::MakeInstance()
{
	return MakeShareable(new FInputLayoutSettingsDetails());
}

void FInputLayoutSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	
}
