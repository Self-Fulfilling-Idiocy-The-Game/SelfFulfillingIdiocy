// Fill out your copyright notice in the Description page of Project Settings.

#include "GlowActor.h"


// Sets default values
AGlowActor::AGlowActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGlowActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGlowActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGlowActor::OnLookAt_Implementation() {}
void AGlowActor::OnLookAway_Implementation() {}