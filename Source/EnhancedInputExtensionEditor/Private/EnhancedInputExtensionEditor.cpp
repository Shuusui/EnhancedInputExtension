//Copyright JosaiProduction. All rights reserved

#include "EnhancedInputExtensionEditor.h"
#include "InputActionCollection.h"
#include "InputActionCollectionDetails.h"

#define LOCTEXT_NAMESPACE "EnhancedInputExtensionEditorModule"

void FEnhancedInputExtensionEditorModule::StartupModule()
{
	RegisterCustomClassLayout<UInputActionCollection>(FOnGetDetailCustomizationInstance::CreateStatic(&FInputActionCollectionDetails::MakeInstance));
}

void FEnhancedInputExtensionEditorModule::ShutdownModule()
{
	UnregisterCustomClassLayout<UInputActionCollection>();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FEnhancedInputExtensionEditorModule, EnhancedInputExtensionEditor)
