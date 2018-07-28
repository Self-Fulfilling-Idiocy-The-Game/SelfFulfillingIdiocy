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
		FRotator rotation = FRotator(0.f, Speed*Direction, 0.f);
		AddActorLocalRotation(rotation);

		float NextPoint = InitialYaw + 91;
		while (NextPoint < -180) NextPoint += 360;
		if ((GetActorRotation().Yaw>NextPoint) && !OpenDirectionReverse && !Open) {
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

		//If other direction
		float NextPointBack = InitialYaw - 91;
		while (NextPointBack < -180) NextPointBack += 360;
		if ((GetActorRotation().Yaw<NextPointBack) && OpenDirectionReverse && !Open) {
			Open = true;
			Moving = false;

			float Direction = 1;

			if (Open) Direction *= -1;
			if (OpenDirectionReverse) Direction *= -1;

			float Yaw;
			if (GetActorRotation().Yaw > InitialYaw - 91) Yaw = InitialYaw - 90;

			while (Yaw < -180) Yaw += 360;

			SetActorRotation(FRotator(0.f, Yaw, 0.f));
		}

		float YawBelow = InitialYaw - Speed;
		float YawAbove = InitialYaw + Speed;
		if ((GetActorRotation().Yaw>YawBelow) && (GetActorRotation().Yaw<YawAbove) && Open) {
			Open = false;
			Moving = false;

			SetActorRotation(FRotator(0.f, InitialYaw, 0.f));
		}
	}
}
void ADoor::OnLookAt_Implementation() {}
void ADoor::OnLookAway_Implementation() {}