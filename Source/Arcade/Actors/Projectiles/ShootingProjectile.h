
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"

#include "ShootingProjectile.generated.h"

UCLASS()
class ARCADE_API AShootingProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	AShootingProjectile();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StaticMesh")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	USphereComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MoveSpeed")
	float Speed;
};
