// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SplineComponent.h"
#include "Patrol.generated.h"

UCLASS()
class SELFFULFILLINGIDIOCY_API APatrol : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APatrol();
	
	///The direction the character moves when move functions are called
	UPROPERTY(BlueprintReadWrite) FVector Direction;

	///Current spline point moving to
	UPROPERTY(BlueprintReadWrite) int SplinePoint;

	///Whether the object is moving forward or backwards
	UPROPERTY(BlueprintReadWrite) bool Forwards;

	///Speed the object is allowed to move
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Patrol Movement") float Speed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FVector ZAxis;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Patrol Movement")
		void MoveForward();

	UFUNCTION(BlueprintCallable, Category = "Patrol Movement")
		void Move(FVector ThisDirection);

	///Sets the next point that the AI should move to on the given Spline course
	UFUNCTION(BlueprintCallable, Category = "Patrol Movement")
		void NextPoint(USplineComponent *Spline);

};
