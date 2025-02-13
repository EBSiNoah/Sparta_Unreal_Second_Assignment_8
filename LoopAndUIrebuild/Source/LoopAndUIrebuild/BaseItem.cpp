// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "Components/SphereComponent.h"

// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(scene);

	collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	collision->SetupAttachment(scene);

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	staticMesh->SetupAttachment(collision);

	collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnItemOverlap);
	collision->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnItemEndOverlap);
}

void ABaseItem::OnItemOverlap(UPrimitiveComponent* overlappedComp,	AActor* otherActor,	UPrimitiveComponent* otherComp,	int32 otherBodyIndex,	bool bFromSweep,	const FHitResult& sweepResult)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		//GEngine->AddOnScreenDe
		ActivateItem(otherActor);
	}
}

void ABaseItem::OnItemEndOverlap(UPrimitiveComponent* overlappedComp,	AActor* otherActor,	UPrimitiveComponent* otherComp,	int32 otherBodyIndex)
{

}

void ABaseItem::ActivateItem(AActor* overlapActor)
{

}

FName ABaseItem::GetItemType() const
{
	return itemType;
}

void ABaseItem::DestroyItem()
{
	Destroy();
}