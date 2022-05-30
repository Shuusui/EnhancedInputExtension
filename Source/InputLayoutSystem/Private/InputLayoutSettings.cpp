#include "InputLayoutSettings.h"

FName UInputLayoutSettings::GetCategoryName() const
{
    return TEXT("Plugins");
}

#if WITH_EDITOR
FText UInputLayoutSettings::GetSectionText() const
{
    return NSLOCTEXT("InputLayouts", "InputLayoutsSection", "Input Layouts");
}

FName UInputLayoutSettings::GetSectionName() const
{
    return TEXT("Input Layouts");
}
#endif
