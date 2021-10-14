// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UCapsuleComponent;
class UMovementComponent;
class UGravitySwitcherComponent;


UCLASS()
class TASK15_API ABall : public AActor
{
	GENERATED_BODY()

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* BallMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UGravitySwitcherComponent* GravitySwitcherComponent;

	ABall();

	virtual void Tick(float DeltaTime) override;

	void SwitchGravityBall();
	void StartMove(float Speed);

protected:
	virtual void BeginPlay() override;

};
