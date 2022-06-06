#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "InputLayoutSettings.generated.h"

//class UInputMappingContext;
//
//USTRUCT(BlueprintType)
//struct INPUTLAYOUTSYSTEM_API FInputLayoutActionKey
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
//	uint8 bShift : 1;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
//	uint8 bCtrl : 1;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
//	uint8 bAlt : 1;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
//	uint8 bCmd : 1;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
//	FKey Key;
//};
//
//USTRUCT(BlueprintType)
//struct INPUTLAYOUTSYSTEM_API FInputLayoutActionKeyMapping
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
//	FName ActionName;
//
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
//	FInputLayoutActionKey OriginalKey;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
//	FInputLayoutActionKey LayoutKey;
//};
//
//USTRUCT(BlueprintType)
//struct INPUTLAYOUTSYSTEM_API FInputLayoutAxisKey
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
//	float Scale;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
//	FKey Key;
//};
//
//USTRUCT(BlueprintType)
//struct INPUTLAYOUTSYSTEM_API FInputLayoutAxisKeyMapping
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
//	FName AxisName;
//
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
//	FInputLayoutAxisKey OriginalKey;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
//	FInputLayoutAxisKey LayoutKey;
//};
//
//USTRUCT(BlueprintType)
//struct INPUTLAYOUTSYSTEM_API FInputLayoutSpeechMapping
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
//	FName ActionName;
//
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
//	FName OriginalSpeechKeyword;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
//	FName LayoutKey;
//};
//
//USTRUCT(BlueprintType)
//struct INPUTLAYOUTSYSTEM_API FInputMappingContextMapping
//{
//	GENERATED_BODY()
//
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
//	TSoftObjectPtr<UInputMappingContext> OriginalMappingContext;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
//	TSoftObjectPtr<UInputMappingContext> LayoutMappingContext;
//};
//
//USTRUCT(BlueprintType)
//struct INPUTLAYOUTSYSTEM_API FInputLayout
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bindings")
//	TArray<FInputLayoutActionKeyMapping> ActionMappings;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bindings")
//	TArray<FInputLayoutAxisKeyMapping> AxisMappings;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bindings")
//	TArray<FInputLayoutSpeechMapping> SpeechMappings;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bindings")
//	TArray<FInputMappingContextMapping> MappingContexts;
//};


UCLASS(Config=InputLayouts, DefaultConfig)
class INPUTLAYOUTSYSTEM_API UInputLayoutSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:


	virtual FName GetCategoryName() const override;

	static FName GetDefaultLayoutName()
	{
		return TEXT("Default");
	}

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FName GetSectionName() const override;
#endif

	//UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Layouts")
	//TMap<FName, FInputLayout> InputLayouts;

	//UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Layouts", meta=(GetOptions="GetLayoutOptions"))
	//FName DefaultLayout;

	//UFUNCTION()
	//TArray<FName> GetLayoutOptions() const
	//{
	//	TArray<FName> OutOptions;
	//	for (const TPair<FName, FInputLayout>& InputLayout : InputLayouts)
	//	{
	//		OutOptions.Add(InputLayout.Key);
	//	}
	//	return OutOptions;
	//}
};