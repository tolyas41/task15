// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GravitySwitcherComponent.generated.h"

class ABall;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TASK15_API UGravitySwitcherComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGravitySwitcherComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void SwitchGravity();
};
