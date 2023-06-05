
#include "ShootingComponent.h"


UShootingComponent::UShootingComponent()
{

}


void UShootingComponent::BeginPlay()
{
	Super::BeginPlay();

	StartShooting();
}

void UShootingComponent::Shoot()
{
	FTransform Transform;
	Transform.SetLocation(GetOwner()->GetActorLocation());

	GetWorld()->SpawnActor<AShootingProjectile>(ShootingProjectile, Transform, FActorSpawnParameters());
}

void UShootingComponent::StartShooting()
{
	GetWorld()
		->GetTimerManager()
		.SetTimer(ShootingTimer, this, &UShootingComponent::Shoot, ShootingInterval, true, ShootingInterval);
}

void UShootingComponent::StopShooting()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}
