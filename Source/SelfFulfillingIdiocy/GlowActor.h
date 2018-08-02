// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlowActor.generated.h"

UCLASS()
class SELFFULFILLINGIDIOCY_API AGlowActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGlowActor();
	UPROPERTY(BlueprintReadWrite)
	UPrimitiveComponent * GlowComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
