// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(scene);

	spawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("spawn box"));
	spawnBox->SetupAttachment(scene);

	itemDataTable = nullptr;
}

void ASpawnVolume::SpawnRandomItem()
{
	if (FItemSpawnRow* selectedRow = GetRandomItem())
	{
		if (UClass* actualClass = selectedRow->ItemClass.Get())
		{
			SpawnItem(actualClass);
			//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("spawn")));
		}
	}
}

FVector ASpawnVolume::GetRandomPointInVolume()const
{
	FVector boxExtent = spawnBox->GetScaledBoxExtent();

	FVector boxOrigin = spawnBox->GetComponentLocation();

	return boxOrigin + FVector(FMath::FRandRange(-boxExtent.X, boxExtent.X), FMath::FRandRange(-boxExtent.Y, boxExtent.Y), FMath::FRandRange(-boxExtent.Z, boxExtent.Z));
}

FItemSpawnRow* ASpawnVolume::GetRandomItem() const
{
	if (!itemDataTable) return nullptr;

	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("get random item")));

	TArray<FItemSpawnRow*> allRows;
	static const FString ContextString(TEXT("ItemSpawnContext"));
	itemDataTable->GetAllRows(ContextString, allRows);

	if (allRows.IsEmpty()) return nullptr;

	float totalChance = 0.0f;
	for (const FItemSpawnRow* row:allRows)
	{
		if (row)
		{
			totalChance += row->SpawnChance;
		}
	}

	const float randValue = FMath::FRandRange(0.0f, totalChance);
	float accumulateChance = 0.0f;

	for (FItemSpawnRow* row : allRows)
	{
		accumulateChance += row->SpawnChance;
		if (randValue <= accumulateChance)
		{
			return row;
		}
	}

	return nullptr;
}

void ASpawnVolume::SpawnItem(TSubclassOf<AActor> itemClass)
{
	if (!itemClass) return;
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("spawn comfirm")));
	GetWorld()->SpawnActor<AActor>(itemClass, GetRandomPointInVolume(), FRotator::ZeroRotator);
}