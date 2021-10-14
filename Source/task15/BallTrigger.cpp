// Fill out your copyright notice in the Description page of Project Settings.

#include "BallTrigger.h"

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
		static int32 score = 0;
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("Score : %i"), score));
		score++;
	}
}