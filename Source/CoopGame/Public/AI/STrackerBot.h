// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STrackerBot.generated.h"

class UStaticMeshComponent;
class USHealthComponent;

UCLASS()
class COOPGAME_API ASTrackerBot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASTrackerBot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USHealthComponent* HealthComp;

	FVector GetNextPathPoint();
	FVector NextPathPoint;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	float MovementForce;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	bool bUseVelcityChange;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	float RequiredDistanceToTarget;

	UFUNCTION()
	void HandleTakeDamage(USHealthComponent* HealthComponent, float Health, float HealthDelta, const class UDamageType* DamageType,
		class AController* InstigatedBy, AActor* DamageCauser);

	UMaterialInstanceDynamic* MatInst;

	void SelfDestruct();

	UPROPERTY(EditDefaultsOnly, Category = "TracketBot")
	UParticleSystem* ExplosionEffect;

	bool bExploded;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	float ExplosionRadius;

	UPROPERTY(EditDefaultsOnly, Category = "TrackerBot")
	float ExplosionDamage;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	
	
};
