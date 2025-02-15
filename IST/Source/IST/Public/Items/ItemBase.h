// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemDataStructs.h"
#include "ItemBase.generated.h"

class UInventoryComponent;

/**
 * 
 */
UCLASS()
class IST_API UItemBase : public UObject
{
	GENERATED_BODY()

public:
	//===========================================================================
	// Properties & Variables
	//===========================================================================
	
	UPROPERTY()
	UInventoryComponent* OwningInventory;
	
	UPROPERTY(VisibleAnywhere, Category = "Item", meta = (UIMin=1, UIMax=100))
	int32 Quantity;
	
	UPROPERTY(VisibleAnywhere, Category="Item")
	FName ID;

	UPROPERTY(VisibleAnywhere, Category="Item")
	EItemType ItemType;

	UPROPERTY(VisibleAnywhere, Category="Item") 
	EItemQuality ItemQuality;

	UPROPERTY(VisibleAnywhere, Category="Item")
	FItemStatistics ItemStatistics;

	UPROPERTY(VisibleAnywhere, Category="Item")
	FItemTextData TextData;

	UPROPERTY(VisibleAnywhere, Category="Item")
	FItemNumericData NumericData;

	UPROPERTY(VisibleAnywhere, Category="Item")
	FItemAssetData AssetData;

	bool bIsCopy;
	bool bIsPickup;

	//===========================================================================
	// Functions
	//===========================================================================
	UItemBase();

	void ResetItemFlags();

	UFUNCTION(Category = "Item")
	UItemBase* CreateItemCopy();

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemStackWeight() const { return Quantity * NumericData.Weight; };

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemSingleWeight() const { return Quantity * NumericData.Weight; };

	UFUNCTION(Category = "Item")
	FORCEINLINE bool IsFullItemStack() const { return Quantity == NumericData.MaxStackSize; };

	UFUNCTION(Category = "Item")
	void SetQuantity(const int32 NewQuantity);

	UFUNCTION(Category = "Item")
	virtual void Use(ATP_TopDownPlayerController* Character);

protected:
	bool operator == (const FName& OtherID) const
	{
		return ID == OtherID;
	}
	
};
