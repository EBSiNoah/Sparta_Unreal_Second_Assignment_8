// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "HealingItem.generated.h"

/**
 * 
 */
UCLASS()
class LOOPANDUIREBUILD_API AHealingItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	AHealingItem();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "heal")
	int32 healAmount;

	virtual void ActivateItem(AActor* activator) override;
};
