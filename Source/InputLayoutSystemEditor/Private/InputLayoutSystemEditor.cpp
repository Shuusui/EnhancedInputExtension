
#include "InputLayoutSystemEditor.h"
#include "InputLayoutSettings.h"
#include "AssetToolsModule.h"
#include "AssetTypeActions_InputLayout.h"
#include "IAssetTools.h"
#include "IAssetTypeActions.h"

#define LOCTEXT_NAMESPACE "InputLayoutSystemEditor"

EAssetTypeCategories::Type FInputLayoutSystemEditorModule::InputAssetsCategory;

void FInputLayoutSystemEditorModule::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	InputAssetsCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Input")), LOCTEXT("InputAssetsCategory", "Input"));
	{
		RegisterAssetTypeActions(AssetTools, MakeShareable(new FAssetTypeActions_InputLayout));
	}
}

void FInputLayoutSystemEditorModule::ShutdownModule()
{
	if (FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools"))
	{
		for (TSharedPtr<IAssetTypeActions>& AssetActions : CreatedAssetTypeActions)
		{
			AssetToolsModule->Get().UnregisterAssetTypeActions(AssetActions.ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();
}

void FInputLayoutSystemEditorModule::RegisterAssetTypeActions(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FInputLayoutSystemEditorModule, InputLayoutSystemEditor)