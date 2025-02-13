// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallCoinItem.h"

ASmallCoinItem::ASmallCoinItem()
{
	pointValue = 10;
	itemType = "SmallCoin";
}


void ASmallCoinItem::ActivateItem(AActor* activator)
{
	Super::ActivateItem(activator);
}