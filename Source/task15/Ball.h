// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UCapsuleComponent;
class UMovementComponent;

UCLASS()
class TASK15_API ABall : public AActor
{
	GENERATED_BODY()
	
private:


public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* BallMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UMovementComponent* BallMoving;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UActorComponent* MoveComp;

	ABall();
	void SwitchGravityBall();
	void StartMove(float Force);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
