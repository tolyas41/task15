// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayersView.h"
#include "Ball.h"
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


APlayersView::APlayersView()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayersView::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), BallToControl, FoundBalls);
}

void APlayersView::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayersView::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("StartMoving", IE_Pressed, this, &APlayersView::StartMoving);
	PlayerInputComponent->BindAction("SwitchGravity", IE_Pressed, this, &APlayersView::SwitchGravity);
}

void APlayersView::StartMoving()
{
	for (auto ball : FoundBalls)
	{
		Cast<ABall>(ball)->StartMove(BallSpeed);
	}
}

void APlayersView::SwitchGravity()
{
	for (auto ball : FoundBalls)
	{
		Cast<ABall>(ball)->SwitchGravityBall();
	}
}
