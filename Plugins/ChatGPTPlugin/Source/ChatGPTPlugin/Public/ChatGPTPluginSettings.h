//Joe Zhang 2/2025
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChatGPTPluginSettings.generated.h"

// ChatGPT Plugin Settings for API configuration

UCLASS(Config = Game, DefaultConfig)
class CHATGPTPLUGIN_API UChatGPTPluginSettings : public UObject
{
    GENERATED_BODY()

public:
    /** OpenAI API Key */
    UPROPERTY(Config, EditAnywhere, Category = "ChatGPT Plugin")
    FString APIKey;

    /** Endpoint URL for the ChatGPT API */
    UPROPERTY(Config, EditAnywhere, Category = "ChatGPT Plugin")
    FString EndpointURL;

    /** Constructor to set default values */
    UChatGPTPluginSettings()
    {
        // Set default values for properties
        EndpointURL = TEXT("https://api.openai.com/v1/chat/completions");
    }
};
