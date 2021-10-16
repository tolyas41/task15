// Fill out your copyright notice in the Description page of Project Settings.


#include "GravitySwitcherComponent.h"
#include "Ball.h"
#include "Components/CapsuleComponent.h"

UGravitySwitcherComponent::UGravitySwitcherComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGravitySwitcherComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UGravitySwitcherComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGravitySwitcherComponent::SwitchGravity()
{
	if (ABall* Ball = GetOwner<ABall>())
	{
		if (Ball->CapsuleComponent->IsGravityEnabled())
		{
			UE_LOG(LogTemp, Warning, TEXT("grav off"));
			Ball->CapsuleComponent->SetEnableGravity(false);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("grav on"));
			Ball->CapsuleComponent->SetEnableGravity(true);
		}
	}
}
