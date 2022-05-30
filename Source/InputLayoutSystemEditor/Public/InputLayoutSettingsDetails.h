
#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FInputLayoutSettingsDetails : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
private:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};