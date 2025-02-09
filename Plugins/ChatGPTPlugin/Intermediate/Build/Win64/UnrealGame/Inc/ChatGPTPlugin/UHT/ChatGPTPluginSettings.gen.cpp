// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChatGPTPlugin/Public/ChatGPTPluginSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChatGPTPluginSettings() {}

// Begin Cross Module References
CHATGPTPLUGIN_API UClass* Z_Construct_UClass_UChatGPTPluginSettings();
CHATGPTPLUGIN_API UClass* Z_Construct_UClass_UChatGPTPluginSettings_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_ChatGPTPlugin();
// End Cross Module References

// Begin Class UChatGPTPluginSettings
void UChatGPTPluginSettings::StaticRegisterNativesUChatGPTPluginSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UChatGPTPluginSettings);
UClass* Z_Construct_UClass_UChatGPTPluginSettings_NoRegister()
{
	return UChatGPTPluginSettings::StaticClass();
}
struct Z_Construct_UClass_UChatGPTPluginSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ChatGPT Plugin Settings for API configuration\n" },
#endif
		{ "IncludePath", "ChatGPTPluginSettings.h" },
		{ "ModuleRelativePath", "Public/ChatGPTPluginSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ChatGPT Plugin Settings for API configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_APIKey_MetaData[] = {
		{ "Category", "ChatGPT Plugin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** OpenAI API Key */" },
#endif
		{ "ModuleRelativePath", "Public/ChatGPTPluginSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "OpenAI API Key" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndpointURL_MetaData[] = {
		{ "Category", "ChatGPT Plugin" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Endpoint URL for the ChatGPT API */" },
#endif
		{ "ModuleRelativePath", "Public/ChatGPTPluginSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Endpoint URL for the ChatGPT API" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_APIKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EndpointURL;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChatGPTPluginSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UChatGPTPluginSettings_Statics::NewProp_APIKey = { "APIKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChatGPTPluginSettings, APIKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_APIKey_MetaData), NewProp_APIKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UChatGPTPluginSettings_Statics::NewProp_EndpointURL = { "EndpointURL", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChatGPTPluginSettings, EndpointURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndpointURL_MetaData), NewProp_EndpointURL_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UChatGPTPluginSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChatGPTPluginSettings_Statics::NewProp_APIKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChatGPTPluginSettings_Statics::NewProp_EndpointURL,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChatGPTPluginSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UChatGPTPluginSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_ChatGPTPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChatGPTPluginSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UChatGPTPluginSettings_Statics::ClassParams = {
	&UChatGPTPluginSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UChatGPTPluginSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UChatGPTPluginSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UChatGPTPluginSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UChatGPTPluginSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UChatGPTPluginSettings()
{
	if (!Z_Registration_Info_UClass_UChatGPTPluginSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UChatGPTPluginSettings.OuterSingleton, Z_Construct_UClass_UChatGPTPluginSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UChatGPTPluginSettings.OuterSingleton;
}
template<> CHATGPTPLUGIN_API UClass* StaticClass<UChatGPTPluginSettings>()
{
	return UChatGPTPluginSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UChatGPTPluginSettings);
UChatGPTPluginSettings::~UChatGPTPluginSettings() {}
// End Class UChatGPTPluginSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UChatGPTPluginSettings, UChatGPTPluginSettings::StaticClass, TEXT("UChatGPTPluginSettings"), &Z_Registration_Info_UClass_UChatGPTPluginSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UChatGPTPluginSettings), 3970243758U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_3687276152(TEXT("/Script/ChatGPTPlugin"),
	Z_CompiledInDeferFile_FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OpenAIAPI_Plugins_ChatGPTPlugin_Source_ChatGPTPlugin_Public_ChatGPTPluginSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
