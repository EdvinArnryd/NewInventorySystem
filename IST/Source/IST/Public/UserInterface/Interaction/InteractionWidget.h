// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionWidget.generated.h"

class AISTCharacter;
class ATP_TopDownPlayerController;
struct FInteractableData;
class UTextBlock;
class UProgressBar;

/**
 * 
 */
UCLASS()
class IST_API UInteractionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Interaction Widget | Player Reference")
	ATP_TopDownPlayerController* PlayerReference;

	void UpdateWidget(const FInteractableData* InteractableData);

protected:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category="Interaction Widget | Interactable Data")
	UTextBlock* NameText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category="Interaction Widget | Interactable Data")
	UTextBlock* ActionText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category="Interaction Widget | Interactable Data")
	UTextBlock* KeyPressText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category="Interaction Widget | Interactable Data")
	UProgressBar* InteractionbProgressBar;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category="Interaction Widget | Interactable Data")
	float CurrentInteractionDuration;

	UFUNCTION(Category ="Interaction Widget | Interactable Data")
	float UpdateInteractionProgress();
	
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
};
