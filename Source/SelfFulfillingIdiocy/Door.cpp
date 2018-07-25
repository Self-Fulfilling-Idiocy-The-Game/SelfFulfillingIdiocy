// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Engine.h"

// Sets default values
ADoor::ADoor() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float Direction = 1;

	if (Open) Direction *= -1;
	if (OpenDirectionReverse) Direction *= -1;

	if (Moving) {
		FRotator rotation = FRotator(0.f, Speed*Direction, 0.f);
		AddActorLocalRotation(rotation);

		FString TheFloatStr = FString::SanitizeFloat(GetActorRotation().Yaw);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatStr);

		if (GetActorRotation().Yaw > -89.f || GetActorRotation().Yaw < 89.f && !Open) {
			Open = true;
			Moving = false;

			float Direction = 1;

			if (Open) Direction *= -1;
			if (OpenDirectionReverse) Direction *= -1;

			float Yaw = (90.f * Direction * -1) - 180.f;
			if (Yaw < -180)Yaw += 360;

			SetActorRotation(FRotator(0.f, (90.f * Direction * -1) - 180.f, 0.f));
		}
		if ((GetActorRotation().Yaw < -179.f && GetActorRotation().Yaw > -181.f) || (GetActorRotation().Yaw > 179.f && GetActorRotation().Yaw < 181.f) && Open) {
			Open = false;
			Moving = false;

			SetActorRotation(FRotator(0.f, -180.f, 0.f));
		}
	}
}
void ADoor::OnLookAt_Implementation() {}
void ADoor::OnLookAway_Implementation() {}

