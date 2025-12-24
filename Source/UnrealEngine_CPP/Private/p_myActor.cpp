// Fill out your copyright notice in the Description page of Project Settings.


#include "p_myActor.h"

// Sets default values
Ap_myActor::Ap_myActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	currentCount = 0;
	eventCount = 0;
}

void Ap_myActor::MoveAndTurn()
{
	Turn();
	Move();
	currentCount++;

	if (currentCount >= 10)
	{
		GetWorldTimerManager().ClearTimer(updateTimerHandle);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Total Distance : %f , Event Count : %d"), totalDistance, eventCount));
		}
	}
}

void Ap_myActor::Turn()
{
	int ranX = FMath::RandRange(0, 360);
	int ranY = FMath::RandRange(0, 360);
	int ranZ = FMath::RandRange(0, 360);
	
	FRotator rotation(ranX, ranY, ranZ);
	SetActorRotation(rotation);
	
}

void Ap_myActor::Move()
{
	FVector currentLocation = GetActorLocation();

	int ranX = FMath::RandRange(0, 500);
	int ranY = FMath::RandRange(0, 500);
	int ranZ = FMath::RandRange(0, 20);
	
	FVector location(ranX, ranY, ranZ);
	SetActorLocation(location);
	
	totalDistance += FVector::Distance(currentLocation, location);
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Black, FString::Printf(TEXT("%d ) location : %s"), currentCount + 1,*location.ToString()));
	}

	int ranNum = FMath::RandRange(0, 1);
	if (ranNum)
		MoveEvent();
}

void Ap_myActor::MoveEvent()
{
	FVector currentScale = GetActorScale3D();
	currentScale.X += 0.5f;

	SetActorScale3D(currentScale);
	
	eventCount++;
}
// Called when the game starts or when spawned
void Ap_myActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(FVector(0, 50, 0));
	
	GetWorldTimerManager().SetTimer(updateTimerHandle, this, &Ap_myActor::MoveAndTurn, 1.0f, true);
	
}

// Called every frame
void Ap_myActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

