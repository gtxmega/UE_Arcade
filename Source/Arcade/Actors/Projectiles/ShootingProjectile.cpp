
#include "ShootingProjectile.h"

AShootingProjectile::AShootingProjectile() : Speed(50.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	SetRootComponent(Collision);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Collision);
}

void AShootingProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShootingProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Direction = GetActorForwardVector();

	Direction *= Speed * DeltaTime;

	AddActorLocalOffset(Direction);
}

