// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"

AHealingItem::AHealingItem()
{
	healAmount = 20.0f;
	itemType = "Heal";
}

void AHealingItem::ActivateItem(AActor* activator)
{
	if (activator && activator->ActorHasTag("Player"))
	{
		//

		DestroyItem();
	}
}