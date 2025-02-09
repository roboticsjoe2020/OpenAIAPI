// Joe Zhang

#include "MyActor.h"

// Constructor: Sets default values
AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true; // Enable Tick() if needed
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // Access plugin settings
    const UChatGPTPluginSettings* Settings = GetDefault<UChatGPTPluginSettings>();

    if (!Settings || Settings->APIKey.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("ChatGPT API Key is not set in the settings."));
        return;
    }

    if (Settings->EndpointURL.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("ChatGPT Endpoint URL is not set in the settings."));
        return;
    }

    // Test the ChatGPT plugin functionality
    TestChatGPT();
}

// Sends a test message to the ChatGPT plugin and logs the response
void AMyActor::TestChatGPT()
{
    FString Prompt = TEXT("Can you briefly introduce Montclair State University?");

    // Get the plugin module instance
    FChatGPTPluginModule& ChatGPTModule = FModuleManager::GetModuleChecked<FChatGPTPluginModule>("ChatGPTPlugin");

    // Send a test message to ChatGPT
    ChatGPTModule.SendMessage(Prompt, [](const FString& Reply)
        {
            // Log the reply in the Output Log
            UE_LOG(LogTemp, Log, TEXT("ChatGPT Reply: %s"), *Reply);
        });
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
