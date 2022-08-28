//Copyright JosaiProduction. All rights Reserved.
#include "InputLayout_Factory.h"
#include "InputLayout.h"

UInputLayout_Factory::UInputLayout_Factory(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SupportedClass = UInputLayout::StaticClass();
	bEditAfterNew = true;
	bCreateNew = true;
}

UObject* UInputLayout_Factory::FactoryCreateNew(UClass* Class, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UInputLayout::StaticClass()));
	return NewObject<UInputLayout>(InParent, Class, InName, Flags | RF_Transactional, Context);
}
