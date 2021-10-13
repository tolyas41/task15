// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GravitySwitcher.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	//CapsuleComp->SetupAttachment(RootComponent);

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	BallMesh->SetupAttachment(CapsuleComp);
	//CapsuleComp->SetEnableGravity(true);

	
	GravitySwitcher = CreateDefaultSubobject<UGravitySwitcher>(TEXT("Gravity Switcher"));

	//BallMoving = CreateDefaultSubobject<UMovementComponent>(TEXT("Ball Moving"));



	CapsuleComp->SetSimulatePhysics(true);
	CapsuleComp->SetEnableGravity(false);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABall::SwitchGravityBall()
{
	if (CapsuleComp->IsGravityEnabled())
	{
		CapsuleComp->SetEnableGravity(false);
	}
	else
	{
		CapsuleComp->SetEnableGravity(true);
	}
}

void ABall::StartMove(float Force)
{

	 FVector ToImpulse = this->GetActorRightVector();
	 CapsuleComp->AddForce(ToImpulse * Force * BallMesh->GetMass());

}