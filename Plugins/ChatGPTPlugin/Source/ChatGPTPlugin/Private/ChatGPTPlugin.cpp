#include "ChatGPTPlugin.h"
#include "ChatGPTPluginSettings.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FChatGPTPluginModule"

void FChatGPTPluginModule::StartupModule()
{
    // Register plugin settings
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->RegisterSettings("Project", "Plugins", "ChatGPT Plugin",
            LOCTEXT("ChatGPTPluginSettingsName", "ChatGPT Plugin"),
            LOCTEXT("ChatGPTPluginSettingsDescription", "Configure the ChatGPT plugin."),
            GetMutableDefault<UChatGPTPluginSettings>());
    }

    UE_LOG(LogTemp, Log, TEXT("ChatGPT Plugin has started."));
}

void FChatGPTPluginModule::ShutdownModule()
{
    // Unregister plugin settings
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "ChatGPT Plugin");
    }

    UE_LOG(LogTemp, Log, TEXT("ChatGPT Plugin has shut down."));
}

void FChatGPTPluginModule::SendMessage(const FString& Message, TFunction<void(const FString&)> Callback)
{
    const UChatGPTPluginSettings* Settings = GetDefault<UChatGPTPluginSettings>();
    if (!Settings || Settings->APIKey.IsEmpty() || Settings->EndpointURL.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("API Key or Endpoint URL is not set in the plugin settings."));
        Callback(TEXT("Error: API Key or Endpoint URL is not set."));
        return;
    }

    FString Url = Settings->EndpointURL;

    // Create the HTTP request
    TSharedPtr<IHttpRequest> HttpRequest = CreateHttpRequest(Url);

    if (!HttpRequest.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create HTTP request."));
        Callback(TEXT("Error: Failed to create HTTP request."));
        return;
    }

    // Create JSON payload
    TArray<TSharedPtr<FJsonValue>> MessagesArray;
    TSharedPtr<FJsonObject> UserMessage = MakeShareable(new FJsonObject());
    UserMessage->SetStringField(TEXT("role"), TEXT("user"));
    UserMessage->SetStringField(TEXT("content"), Message);
    MessagesArray.Add(MakeShareable(new FJsonValueObject(UserMessage)));

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    JsonObject->SetStringField(TEXT("model"), TEXT("gpt-3.5-turbo"));
    JsonObject->SetArrayField(TEXT("messages"), MessagesArray);
    JsonObject->SetNumberField(TEXT("max_tokens"), 150);
    JsonObject->SetNumberField(TEXT("temperature"), 0.7);

    // Serialize JSON payload
    FString Payload;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Payload);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    HttpRequest->SetContentAsString(Payload);

    // Set up the response handler
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &FChatGPTPluginModule::OnResponseReceived, Callback);
    HttpRequest->ProcessRequest();
}

//Creates and configures the HTTP request with headers.
TSharedPtr<IHttpRequest> FChatGPTPluginModule::CreateHttpRequest(const FString& Url)
{
    TSharedPtr<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
    const UChatGPTPluginSettings* Settings = GetDefault<UChatGPTPluginSettings>();
    if (!Settings || Settings->APIKey.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("API Key is not set."));
        return nullptr;
    }

    Request->SetVerb(TEXT("POST"));
    Request->SetURL(Url);
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Settings->APIKey);
    return Request;
}

//Handles the HTTP response and passes data to ParseResponse().
void FChatGPTPluginModule::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, TFunction<void(const FString&)> Callback)
{
    if (bWasSuccessful && Response.IsValid())
    {
        FString Reply = Response->GetContentAsString();
        ParseResponse(Reply, Callback);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("HTTP request failed."));
        Callback(TEXT("Error: Unable to reach ChatGPT API."));
    }
}

void FChatGPTPluginModule::ParseResponse(const FString& Reply, TFunction<void(const FString&)> Callback)
{
    TSharedPtr<FJsonObject> JsonResponse;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Reply);

    if (FJsonSerializer::Deserialize(Reader, JsonResponse))
    {
        const TArray<TSharedPtr<FJsonValue>>* Choices;
        if (JsonResponse->TryGetArrayField(TEXT("choices"), Choices))
        {
            for (const auto& Choice : *Choices)
            {
                const TSharedPtr<FJsonObject>* Message;
                if (Choice->AsObject()->TryGetObjectField(TEXT("message"), Message))
                {
                    FString Content = (*Message)->GetStringField(TEXT("content"));
                    Callback(Content);
                    return;
                }
            }
        }
    }

    Callback(TEXT("Error: Unable to parse ChatGPT response."));
}

//Cleans up the localization namespace to prevent unintended carryover into other files
#undef LOCTEXT_NAMESPACE

//Registers the module with Unreal Engine so it can be properly loaded and managed.
IMPLEMENT_MODULE(FChatGPTPluginModule, ChatGPTPlugin)
