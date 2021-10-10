// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/MovementComponent.h"

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

	
	MoveComp = CreateDefaultSubobject<UActorComponent>(TEXT("MoveComp"));

	BallMoving = CreateDefaultSubobject<UMovementComponent>(TEXT("Ball Moving"));



}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	CapsuleComp->SetSimulatePhysics(true);
	CapsuleComp->SetEnableGravity(false);
	Super::BeginPlay();
	//UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(RootComponent);
	//virtual void AddRadialImpulse(FVector Origin, float Radius, float Strength, enum ERadialImpulseFalloff Falloff, bool bVelChange = false);


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
		//CapsuleComp->SetSimulatePhysics(false);
		CapsuleComp->SetEnableGravity(false);
	}
	else
	{
		//CapsuleComp->SetSimulatePhysics(true);
		CapsuleComp->SetEnableGravity(true);
	}
}

void ABall::StartMove(float Force)
{

	 //= { 0.0f, 100.0f, 0.0f };
	 FVector ToImpulse = this->GetActorRightVector();
	//CapsuleComp->AddRadialImpulse(ToImpulse, 10, 10, ERadialImpulseFalloff::RIF_Constant);
	CapsuleComp->AddForce(ToImpulse * Force * BallMesh->GetMass());

}