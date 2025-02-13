// Fill out your copyright notice in the Description page of Project Settings.


#include "MineItem.h"
#include "Components/SphereComponent.h"

AMineItem::AMineItem()
{
	explosionDelay = 5.0f;
	explosionRadius = 300.0f;
	explosionDamage = 30.0f;
	itemType = "Mine";

	explosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	explosionCollision->InitSphereRadius(explosionRadius);
	explosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	explosionCollision->SetupAttachment(scene);
}

void AMineItem::ActivateItem(AActor* activator)
{
	GetWorld()->GetTimerManager().SetTimer(explosionTimerHandle, this, &AMineItem::Explode, explosionDelay);
	//DestroyItem();
}

void AMineItem::Explode()
{
	TArray<AActor*> overlappingActors;
	explosionCollision->GetOverlappingActors(overlappingActors);

	for (AActor* actor : overlappingActors)
	{
		if (actor && actor->ActorHasTag("Player"))
		{
			//
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Player damaged %d by MineItem"), explosionDamage));
		}
	}

	DestroyItem();
}