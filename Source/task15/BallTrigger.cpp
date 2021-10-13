// Fill out your copyright notice in the Description page of Project Settings.


#include "BallTrigger.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)

ABallTrigger::ABallTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ABallTrigger::OnOverlap);	
}

void ABallTrigger::BeginPlay()
{
	Super::BeginPlay();

}

void ABallTrigger::OnOverlap(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		PrintString("Win!");
	}
}