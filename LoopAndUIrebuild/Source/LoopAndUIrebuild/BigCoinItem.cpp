// Fill out your copyright notice in the Description page of Project Settings.


#include "BigCoinItem.h"

ABigCoinItem::ABigCoinItem()
{
	pointValue = 50;
	itemType = "BigCoin";
}

void ABigCoinItem::ActivateItem(AActor* activator)
{
	Super::ActivateItem(activator);
}