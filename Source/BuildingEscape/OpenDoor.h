// Copyright Ben Tristem 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(BlueprintAssignable)
		FDoorRequest OnOpen;

	UPROPERTY(BlueprintAssignable)
		FDoorRequest OnClose;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 50.f;

	// The owning door
	AActor* Owner = nullptr;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
};
