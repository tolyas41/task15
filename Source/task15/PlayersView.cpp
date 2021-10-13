// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersView.h"
#include "Ball.h"

// Sets default values
APlayersView::APlayersView()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayersView::BeginPlay()
{
	Super::BeginPlay();
	Ball = GetWorld()->SpawnActor<ABall>(BallToControl, SpawnLocation, SpawnRotation);
}

// Called every frame
void APlayersView::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayersView::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("StartMoving", IE_Pressed, this, &APlayersView::StartMoving);
	PlayerInputComponent->BindAction("SwitchGravity", IE_Pressed, this, &APlayersView::SwitchGravity);
}

void APlayersView::StartMoving()
{
	Ball->StartMove(BallSpeed);
}

void APlayersView::SwitchGravity()
{
	Ball->SwitchGravityBall();
}
