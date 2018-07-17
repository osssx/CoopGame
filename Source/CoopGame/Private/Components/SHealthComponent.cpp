// Fill out your copyright notice in the Description page of Project Settings.

#include "SHealthComponent.h"


// Sets default values for this component's properties
USHealthComponent::USHealthComponent()
{
	DefaultHealth = 100;

}


// Called when the game starts
void USHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetOwner();
	if (MyOwner) 
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &USHealthComponent::HandleAnyDamage);
	}
	Health = DefaultHealth;
}

void USHealthComponent::HandleAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0) {
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.f, DefaultHealth);
	UE_LOG(LogTemp, Log, TEXT("Health Changed: %s"), *FString::SanitizeFloat(Health));
}

