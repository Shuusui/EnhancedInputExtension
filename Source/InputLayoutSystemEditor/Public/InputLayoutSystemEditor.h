//Copyright JosaiProduction. All rights Reserved.
#pragma once
#include "CoreMinimal.h"

#include "EditorModuleUtilities.h"
#include "AssetTypeCategories.h"



class FInputLayoutSystemEditorModule : public FExtendedEditorModule
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static uint32 GetInputAssetCategories() 
	{
		return InputAssetsCategory;
	}
private:
	static EAssetTypeCategories::Type InputAssetsCategory;
};
