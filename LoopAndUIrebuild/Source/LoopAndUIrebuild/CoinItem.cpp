// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"

ACoinItem::ACoinItem()
{
	pointValue = 0;
	itemType = "DefaultCoin";
}

void ACoinItem::ActivateItem(AActor* activator)
{
	if (activator && activator->ActorHasTag("Player"))
	{
		//

		DestroyItem();
	}
}