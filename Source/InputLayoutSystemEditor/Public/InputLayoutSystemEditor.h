//Copyright JosaiProduction. All rights Reserved.
#include "CoreMinimal.h"
#include "PropertyEditorDelegates.h"
#include "Modules/ModuleManager.h"
#include "AssetTypeCategories.h"

class IAssetTypeActions;

class FInputLayoutSystemEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static EAssetTypeCategories::Type GetInputAssetCategories() {return InputAssetsCategory; }

private:

	void RegisterAssetTypeActions(class IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);

	static EAssetTypeCategories::Type InputAssetsCategory;

	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;

	template <typename T>
	void RegisterCustomClassLayout(FOnGetDetailCustomizationInstance DetailLayoutDelegate)
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.RegisterCustomClassLayout(T::StaticClass()->GetFName(), DetailLayoutDelegate);
	}

	template<typename T> 
	void RegisterCustomPropertyTypeLayout(FOnGetPropertyTypeCustomizationInstance CustomizationLayoutDelegate)
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.RegisterCustomPropertyTypeLayout(T::StaticStruct()->GetFName(), CustomizationLayoutDelegate);
	}

	template<typename T>
	void UnregisterCustomClassLayout()
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.UnregisterCustomClassLayout(T::StaticClass()->GetFName());
	}

	template<typename T>
	void UnregisterCustomPropertyTypeLayout()
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.UnregisterCustomPropertyTypeLayout(T::StaticStruct()->GetFName());
	}
};
