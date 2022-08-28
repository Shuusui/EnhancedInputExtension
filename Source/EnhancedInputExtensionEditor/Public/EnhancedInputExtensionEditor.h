//Copyright JosaiProduction. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "EditorModuleUtilities.h"

class FEnhancedInputExtensionEditorModule : public FExtendedEditorModule
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
