// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawnRow.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class LOOPANDUIREBUILD_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnRandomItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spawn")
	USceneComponent* scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn")
	UBoxComponent* spawnBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	UDataTable* itemDataTable;

	UFUNCTION(BlueprintCallable, Category="Spawn")
	FVector GetRandomPointInVolume() const;

	FItemSpawnRow* GetRandomItem() const;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnItem(TSubclassOf<AActor> itemClass);
};
