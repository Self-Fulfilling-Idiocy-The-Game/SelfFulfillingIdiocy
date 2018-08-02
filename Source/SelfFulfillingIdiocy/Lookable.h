// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lookable.generated.h"

UCLASS(Abstract)
class SELFFULFILLINGIDIOCY_API ALookable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALookable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Lookable")
	void OnLookAt();
	virtual void OnLookAt_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Lookable")
	void OnLookAway();
	virtual void OnLookAway_Implementation();
	
};
