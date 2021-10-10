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

public:
	// Sets default values for this pawn's properties
	APlayersView();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, Category = "SpawnLocation")
		FVector SpawnLocation;

	UPROPERTY(EditAnywhere, Category = "SpawnLocation")
		FRotator SpawnRotation;

	UPROPERTY(EditAnywhere, Category = "BallSpeed")
		float BallSpeed = 5000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Control")
	TSubclassOf<ABall> BallToControl;

	UPROPERTY()
	ABall* Ball;

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void StartMoving();
	void SwitchGravity();
};
