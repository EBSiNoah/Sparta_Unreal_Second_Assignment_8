// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IItemInterface.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

class LOOPANDUIREBUILD_API IItemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void OnItemOverlap(/*AActor* overlapActor*/
		UPrimitiveComponent* overlappedComp,
		AActor* otherActor,
		UPrimitiveComponent* otherComp,
		int32 otherBodyIndex,
		bool bFromSweep,
		const FHitResult& sweepResult)=0;
	UFUNCTION()
	virtual void OnItemEndOverlap(/*AActor* overlapActor*/
		UPrimitiveComponent* overlappedComp,
		AActor* otherActor,
		UPrimitiveComponent* otherComp,
		int32 otherBodyIndex)=0;
	virtual void ActivateItem(AActor* overlapActor) = 0;
	virtual FName GetItemType() const = 0;
};
