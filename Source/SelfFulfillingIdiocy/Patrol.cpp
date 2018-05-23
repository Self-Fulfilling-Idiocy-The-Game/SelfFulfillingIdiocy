// Fill out your copyright notice in the Description page of Project Settings.

#include "Patrol.h"
using namespace std;


// Sets default values
APatrol::APatrol() : ZAxis(0.f, 0.f, 1.f), SplinePoint(0), Forwards(true)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Direction = GetActorForwardVector();
}

// Called when the game starts or when spawned
void APatrol::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APatrol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APatrol::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APatrol::MoveForward()
{
	Move(Direction);
}

void APatrol::Move(FVector ThisDirection)
{
	AddMovementInput(ThisDirection, 1, false);
}

void APatrol::NextPoint(USplineComponent *Spline)
{
	if (Spline->IsClosedLoop()) {
		SplinePoint++;
		if (SplinePoint >= Spline->GetNumberOfSplinePoints()) {
			SplinePoint = 0;
		}
	}
	else {
		if (Forwards) {
			SplinePoint++;
			if (SplinePoint >= Spline->GetNumberOfSplinePoints()) {
				SplinePoint -= 2;
				Forwards = false;
			}
		}
		else {
			SplinePoint--;
			if (SplinePoint < 0) {
				SplinePoint += 2;
				Forwards = true;
			}
		}
	}

}
