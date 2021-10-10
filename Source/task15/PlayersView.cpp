// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersView.h"
#include "Ball.h"

// Sets default values
APlayersView::APlayersView()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayersView::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters SpawnParams;
	Ball = GetWorld()->SpawnActor<ABall>(BallToControl, SpawnLocation, SpawnRotation);
	//AActor* SpawnBallRef = GetWorld()->SpawnActor<AActor>(BallToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

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
	UE_LOG(LogTemp, Warning, TEXT("adfdfdfdf"));

}
void APlayersView::SwitchGravity()
{
	//ABall* BallRef = FindObject<ABall>(BallRef, "Ball");
	//ABall::SwitchGravityBall();
	//BallToControl->SwitchGravityBall();
	UE_LOG(LogTemp, Warning, TEXT("TRTdfadfargergergreRT"));
	Ball->SwitchGravityBall();
}
