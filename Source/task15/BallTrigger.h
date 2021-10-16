// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "BallTrigger.generated.h"


UCLASS()
class TASK15_API ABallTrigger : public ATriggerVolume
{
	GENERATED_BODY()

public:
	ABallTrigger();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlap(class AActor* OverlappedActor, class AActor* OtherActor);

	int32 score{ 0 };

};
