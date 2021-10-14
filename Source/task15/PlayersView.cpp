// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersView.h"
#include "Ball.h"
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values
APlayersView::APlayersView()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayersView::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), BallToControl, FoundActors);
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
	for (auto ball : FoundActors)
	{
		Cast<ABall>(ball)->StartMove(BallSpeed);
	}
}

void APlayersView::SwitchGravity()
{
	for (auto ball : FoundActors)
	{
		Cast<ABall>(ball)->SwitchGravityBall();
	}
}
