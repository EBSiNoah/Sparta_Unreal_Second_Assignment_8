// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "MineItem.generated.h"

/**
 * 
 */
UCLASS()
class LOOPANDUIREBUILD_API AMineItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	AMineItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* explosionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float explosionDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float explosionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float explosionDamage;

	FTimerHandle explosionTimerHandle;

	virtual void ActivateItem(AActor* activator) override;

	void Explode();
};
