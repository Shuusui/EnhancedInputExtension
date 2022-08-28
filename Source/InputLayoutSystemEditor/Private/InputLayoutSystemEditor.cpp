//Copyright JosaiProduction. All rights Reserved.
#include "InputLayoutSystemEditor.h"
#include "InputLayoutSettings.h"
#include "AssetToolsModule.h"
#include "AssetTypeActions_InputLayout.h"
#include "IAssetTools.h"
#include "IAssetTypeActions.h"
#include "InputLayoutDetails.h"
#include "InputLayout.h"

#define LOCTEXT_NAMESPACE "InputLayoutSystemEditor"
EAssetTypeCategories::Type FInputLayoutSystemEditorModule::InputAssetsCategory;

void FInputLayoutSystemEditorModule::StartupModule()
{
	RegisterCustomClassLayout<UInputLayout>(FOnGetDetailCustomizationInstance::CreateStatic(&FInputLayoutDetails::MakeInstance));
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	InputAssetsCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Input")), LOCTEXT("InputAssetsCategory", "Input"));
	{
		RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_InputLayout));
	}
}

void FInputLayoutSystemEditorModule::ShutdownModule()
{
	UnregisterCustomClassLayout<UInputLayout>();
	UnregisterAssetTypeActions();
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FInputLayoutSystemEditorModule, InputLayoutSystemEditor)