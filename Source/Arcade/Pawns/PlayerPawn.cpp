
#include "PlayerPawn.h"


APlayerPawn::APlayerPawn() : Sensitivity(1.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SetRootComponent(BoxCollision);

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	PawnMesh->SetupAttachment(BoxCollision);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	ShootingComponent = CreateDefaultSubobject<UShootingComponent>(TEXT("ShootingComponent"));

}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &APlayerPawn::OnTouchPressed);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &APlayerPawn::OnTouchMove);
}

void APlayerPawn::PossessedBy(AController* NewController)
{
	PlayerController = Cast<APlayerController>(NewController);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerPawn::OnTouchPressed(ETouchIndex::Type touchIndex, FVector location)
{
	TouchLocation = FVector2D(location);
}

void APlayerPawn::OnTouchMove(ETouchIndex::Type touchIndex, FVector location)
{
	FVector2D TouchDelta = FVector2D(TouchLocation.X - location.X, TouchLocation.Y - location.Y);

	TouchDelta *= Sensitivity;

	FVector NewLocation = GetActorLocation();

	NewLocation.X = FMath::Clamp(NewLocation.X + TouchDelta.Y, -500.0f, 500.0f);
	NewLocation.Y = FMath::Clamp(NewLocation.Y + TouchDelta.X * -1.0f, -600.0f, 600.0f);

	SetActorLocation(NewLocation);

	TouchLocation = FVector2D(location.X, location.Y);
}



