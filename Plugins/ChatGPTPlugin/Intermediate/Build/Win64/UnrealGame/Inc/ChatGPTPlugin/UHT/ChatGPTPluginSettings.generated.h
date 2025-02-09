// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ChatGPTPluginSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHATGPTPLUGIN_ChatGPTPluginSettings_generated_h
#error "ChatGPTPluginSettings.generated.h already included, missing '#pragma once' in ChatGPTPluginSettings.h"
#endif
#define CHATGPTPLUGIN_ChatGPTPluginSettings_generated_h

#define FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUChatGPTPluginSettings(); \
	friend struct Z_Construct_UClass_UChatGPTPluginSettings_Statics; \
public: \
	DECLARE_CLASS(UChatGPTPluginSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChatGPTPlugin"), NO_API) \
	DECLARE_SERIALIZER(UChatGPTPluginSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UChatGPTPluginSettings(UChatGPTPluginSettings&&); \
	UChatGPTPluginSettings(const UChatGPTPluginSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UChatGPTPluginSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChatGPTPluginSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UChatGPTPluginSettings) \
	NO_API virtual ~UChatGPTPluginSettings();


#define FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_9_PROLOG
#define FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_12_INCLASS_NO_PURE_DECLS \
	FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHATGPTPLUGIN_API UClass* StaticClass<class UChatGPTPluginSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
