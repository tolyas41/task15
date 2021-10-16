// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GravitySwitcherComponent.h"


ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	RootComponent = CapsuleComponent;

	BallMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh Component"));
	BallMeshComponent->SetupAttachment(CapsuleComponent);

	GravitySwitcherComponent = CreateDefaultSubobject<UGravitySwitcherComponent>(TEXT("Gravity Switcher Component"));
}

void ABall::BeginPlay()
{
	Super::BeginPlay();
	CapsuleComponent->SetSimulatePhysics(true);
	CapsuleComponent->SetEnableGravity(false);

}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABall::SwitchGravityBall()
{
	GravitySwitcherComponent->SwitchGravity();
}

void ABall::StartMove(float Force)
{
	 FVector ToImpulse = this->GetActorRightVector();
	 CapsuleComponent->AddForce(ToImpulse * Force * BallMeshComponent->GetMass());
}