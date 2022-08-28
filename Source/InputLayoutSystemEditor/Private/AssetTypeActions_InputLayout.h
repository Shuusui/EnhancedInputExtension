//Copyright JosaiProduction. All rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "IAssetTypeActions.h"
#include "AssetTypeActions/AssetTypeActions_DataAsset.h"
#include "InputLayout.h"
#include "InputLayoutSystemEditor.h"

class FAssetTypeActions_InputLayout : public FAssetTypeActions_DataAsset
{
public:
	virtual FText GetName() const override {return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_InputLayout", "Input Layout"); }
	virtual uint32 GetCategories() override { return FInputLayoutSystemEditorModule::GetInputAssetCategories(); }
	virtual FColor GetTypeColor() const override { return FColor(255, 255, 127); }
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_InputLayout", "A layout which will change keys of existing inputs at runtime"); }
	virtual class UClass* GetSupportedClass() const override { return UInputLayout::StaticClass(); }
};