#include "InputLayoutSystemEditor.h"
#include "InputLayoutSettings.h"

void FInputLayoutSystemEditorModule::StartupModule()
{
	RegisterCustomClassLayout<UInputLayoutSettings>(FOnGetDetailCustomizationInstance::CreateStatic(&FInputLayoutSettingsDetails::MakeInstance));
}

void FInputLayoutSystemEditorModule::ShutdownModule()
{
	UnregisterCustomClassLayout<UInputLayoutSettings>();
}

IMPLEMENT_MODULE(FInputLayoutSystemEditorModule, InputLayoutSystemEditor)