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

	if(InitialYaw == 0.1234f) InitialYaw = GetActorRotation().Yaw;

	if (Moving) {
		FString TheFloatStr = FString::SanitizeFloat(GetActorRotation().Yaw);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatStr);
		FString TheFloatStr2 = FString::SanitizeFloat(GetActorRotation().Yaw + Speed * Direction);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatStr2);

		FRotator rotation = FRotator(0.f, Speed*Direction, 0.f);
		AddActorLocalRotation(rotation);

		FString TheFloatStr3 = FString::SanitizeFloat(GetActorRotation().Yaw);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatStr3);

		if ((GetActorRotation().Yaw>InitialYaw +91) && !Open) {
			Open = true;
			Moving = false;

			float Direction = 1;

			if (Open) Direction *= -1;
			if (OpenDirectionReverse) Direction *= -1;

			float Yaw;
			if (GetActorRotation().Yaw > InitialYaw + 91) Yaw = InitialYaw + 90;

			while (Yaw < -180) Yaw += 360;

			SetActorRotation(FRotator(0.f, Yaw, 0.f));
		}
		if ((GetActorRotation().Yaw>InitialYaw -1) && (GetActorRotation().Yaw<InitialYaw +1) && Open) {
			Open = false;
			Moving = false;

			SetActorRotation(FRotator(0.f, InitialYaw, 0.f));
		}
	}
}
void ADoor::OnLookAt_Implementation() {}
void ADoor::OnLookAway_Implementation() {}