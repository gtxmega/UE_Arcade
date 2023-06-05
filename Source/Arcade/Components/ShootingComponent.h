
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Actors/Projectiles/ShootingProjectile.h"

#include "ShootingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADE_API UShootingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UShootingComponent();

protected:

	virtual void BeginPlay() override;

	void Shoot();

public:	

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void StartShooting();

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void StopShooting();

protected:

	FTimerHandle ShootingTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	float ShootingInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TSubclassOf<AShootingProjectile> ShootingProjectile;

};
