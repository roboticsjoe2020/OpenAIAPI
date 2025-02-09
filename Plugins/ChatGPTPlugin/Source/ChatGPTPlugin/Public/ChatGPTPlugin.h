//Joe Zhang, 2/2025
#pragma once
#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "ChatGPTPluginSettings.h"

 // The main module class for the ChatGPT plugin 
class CHATGPTPLUGIN_API FChatGPTPluginModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	/** Sends a message to the ChatGPT API */
	void SendMessage(const FString& Message, TFunction<void(const FString&)> Callback);

private:
	/** Helper function to create an HTTP request */
	TSharedPtr<IHttpRequest> CreateHttpRequest(const FString& Url);
	/** Parses the HTTP response (forward declaration) */
	void ParseResponse(const FString& Reply, TFunction<void(const FString&)> Callback);
	/** Handles the HTTP response */
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response,
		bool bWasSuccessful, TFunction<void(const FString&)> Callback);
};