// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GravitySwitcher.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = CapsuleComp;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	BallMesh->SetupAttachment(CapsuleComp);

	GravitySwitcher = CreateDefaultSubobject<UGravitySwitcher>(TEXT("Gravity Switcher"));
}

void ABall::BeginPlay()
{
	Super::BeginPlay();
	CapsuleComp->SetSimulatePhysics(true);
	CapsuleComp->SetEnableGravity(false);

}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABall::SwitchGravityBall()
{
	GravitySwitcher->SwitchGravity();
}

void ABall::StartMove(float Speed)
{
	 FVector ToImpulse = this->GetActorRightVector();
	 CapsuleComp->AddForce(ToImpulse * Speed * BallMesh->GetMass());
}