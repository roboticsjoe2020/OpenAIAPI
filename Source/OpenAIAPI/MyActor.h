// Joe Zhang 2/2025

#pragma once

#include "CoreMinimal.h"
#include "ChatGPTPlugin/Public/ChatGPTPlugin.h"
#include "ChatGPTPlugin/Public/ChatGPTPluginSettings.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

//AMyActor is a test actor class designed to verify the functionality of the ChatGPT plugin.
 
UCLASS()
class OPENAIAPI_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    // Constructor: Sets default values for this actor's properties
    AMyActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    //Sends a test message to the ChatGPT plugin and logs the response.    
    void TestChatGPT();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};

