// Fill out your copyright notice in the Description page of Project Settings.


#include "GravitySwitcher.h"
#include "Ball.h"

// Sets default values for this component's properties
UGravitySwitcher::UGravitySwitcher()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UGravitySwitcher::BeginPlay()
{
	Super::BeginPlay();

	BindToInput();
	SwitchGravity();
}

void UGravitySwitcher::BindToInput()
{
	UInputComponent* InputComponent = NewObject<UInputComponent>(this);
	InputComponent->RegisterComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("SwitchGravity", IE_Pressed, this, &UGravitySwitcher::SwitchGravity);

		// Bind inputs here
		// InputComponent->BindAction("Jump", IE_Pressed, this, &AUnrealisticPawn::Jump);
		// etc...

		// Now hook up our InputComponent to one in a Player
		// Controller, so that input flows down to us
		//EnableInput(GetWorld()->GetFirstPlayerController());
	}
}


// Called every frame
void UGravitySwitcher::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGravitySwitcher::SwitchGravity()
{

	ABall* TargetActor = GetOwner<ABall>();
	if (TargetActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("TRTdfadfargergergreRT"));
		TargetActor->SwitchGravityBall();
	}
	else return;
}
