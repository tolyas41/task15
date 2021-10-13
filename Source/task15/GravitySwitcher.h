// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GravitySwitcher.generated.h"

class ABall;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TASK15_API UGravitySwitcher : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGravitySwitcher();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	ABall* TargetActor;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void SwitchGravity();
};
