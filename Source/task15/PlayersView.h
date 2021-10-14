// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayersView.generated.h"


class ABall;

UCLASS()
class TASK15_API APlayersView : public APawn
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	TArray<AActor*> FoundBalls;

public:	
	APlayersView();

	UPROPERTY(EditAnywhere, Category = "SpawnLocation")
	FVector SpawnLocation;

	UPROPERTY(EditAnywhere, Category = "SpawnLocation")
	FRotator SpawnRotation;

	UPROPERTY(EditAnywhere, Category = "BallSpeed")
	float BallSpeed = 15000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Control")
	TSubclassOf<ABall> BallToControl;

	UPROPERTY()
	ABall* Ball;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void StartMoving();
	void SwitchGravity();
};
