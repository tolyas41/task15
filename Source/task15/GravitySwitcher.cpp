// Fill out your copyright notice in the Description page of Project Settings.


#include "GravitySwitcher.h"
#include "Ball.h"
#include "Components/CapsuleComponent.h"

UGravitySwitcher::UGravitySwitcher()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UGravitySwitcher::BeginPlay()
{
	Super::BeginPlay();
	TargetActor = GetOwner<ABall>();
}



// Called every frame
void UGravitySwitcher::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGravitySwitcher::SwitchGravity()
{

	if (TargetActor)
	{
		if (TargetActor->CapsuleComp->IsGravityEnabled())
		{
			UE_LOG(LogTemp, Warning, TEXT("grav off"));
			TargetActor->CapsuleComp->SetEnableGravity(false);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("grav on"));
			TargetActor->CapsuleComp->SetEnableGravity(true);
		}
	}
	else return;
}
