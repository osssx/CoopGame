// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerupActor.h"


// Sets default values
ASPowerupActor::ASPowerupActor()
{
	PowerupInterval = 0;
	TotalNumOfTicks = 0;

}

// Called when the game starts or when spawned
void ASPowerupActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void ASPowerupActor::OnTickPowerup()
{
	TicksProcessed++;
	OnPowerupTicked();
	if (TicksProcessed >= TotalNumOfTicks)
	{
		OnExpired();
		GetWorldTimerManager().ClearTimer(TimeHandle_PowerupTick);
	}
}

void ASPowerupActor::ActivatePowerup()
{
	if (PowerupInterval > 0.f)
	{
		GetWorldTimerManager().SetTimer(TimeHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerup, PowerupInterval, true, 0.f);
	}
	else
	{
		OnTickPowerup();
	}
}

