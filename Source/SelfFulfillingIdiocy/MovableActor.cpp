// Fill out your copyright notice in the Description page of Project Settings.

#include "MovableActor.h"


// Sets default values
AMovableActor::AMovableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovableActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMovableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AMovableActor::OnLookAt_Implementation() {}
void AMovableActor::OnLookAway_Implementation() {}