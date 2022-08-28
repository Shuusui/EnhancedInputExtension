#pragma once
#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FInputLayoutDetails : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance()
	{
		return MakeShareable(new FInputLayoutDetails());
	}

private:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder);
};

