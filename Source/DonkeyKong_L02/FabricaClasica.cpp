// Fill out your copyright notice in the Description page of Project Settings.

#include "EspinasAfiladas.h"
#include "TrampaFuego.h"
#include "Engine/World.h"
#include "Engine.h"
#include "FabricaClasica.h"

// Sets default values
AFabricaClasica::AFabricaClasica()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FABRICA CLASICA CREADA"));
	}

}

// Called when the game starts or when spawned
void AFabricaClasica::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaClasica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

IEstorboEspinas* AFabricaClasica::CrearEspina() {
    // Obt�n el puntero al World
    UWorld* World = GetWorld();
    if (!World) return nullptr;

    // Configuraci�n de ubicaci�n y rotaci�n
    FVector SpawnLocation = FVector(0.0f, 0.0f, 100.0f);
    FRotator SpawnRotation = FRotator(0.0f, 90.0f, 0.0f);

    // Crea el actor
    AEspinasAfiladas* EspinasAfiladas = World->SpawnActor<AEspinasAfiladas>(SpawnLocation, SpawnRotation);

    // Devuelve el puntero a la interfaz, asumiendo que EspinasAfiladas implementa IEstorboEspinas
    return EspinasAfiladas;
}

IEstorboTrampas* AFabricaClasica::CrearTrampa() {
    // Obt�n el puntero al World
    UWorld* World = GetWorld();
    if (!World) return nullptr;

    // Configuraci�n de ubicaci�n y rotaci�n
    FVector SpawnLocation = FVector(0.0f, 0.0f, 100.0f);
    FRotator SpawnRotation = FRotator(0.0f, 90.0f, 0.0f);

    // Crea el actor
    ATrampaFuego* TrampaFuego = World->SpawnActor<ATrampaFuego>(SpawnLocation, SpawnRotation);

    // Devuelve el puntero a la interfaz, asumiendo que TrampaFuego implementa IEstorboTrampas
    return TrampaFuego;
}

