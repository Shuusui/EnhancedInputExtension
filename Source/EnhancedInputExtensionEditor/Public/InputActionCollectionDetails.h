#pragma once
#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FInputActionCollectionDetails : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance()
	{
		return MakeShareable(new FInputActionCollectionDetails());
	}
private:
	virtual void CustomizeDetails( IDetailLayoutBuilder& DetailBuilder ) override;

};