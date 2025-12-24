// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "p_myActor.generated.h"

UCLASS()
class UNREALENGINE_CPP_API Ap_myActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ap_myActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "currentCount");//editor에 쓰거나 볼수있음~
	int currentCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "totalDistance");
	float totalDistance;
	int eventCount;
private:
	void Turn();
	void Move();
	void MoveEvent();
	void MoveAndTurn();
	FTimerHandle updateTimerHandle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
