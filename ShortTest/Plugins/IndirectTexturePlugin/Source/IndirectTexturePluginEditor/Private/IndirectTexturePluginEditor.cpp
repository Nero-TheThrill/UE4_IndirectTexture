// Copyright Epic Games, Inc. All Rights Reserved.

#include "IndirectTexturePluginEditor.h"

#define LOCTEXT_NAMESPACE "FIndirectTexturePluginEditorModule"

void FIndirectTexturePluginEditorModule::StartupModule()
{
	IndirectTextureActions = MakeShared<FIndirectTextureActions>();
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(IndirectTextureActions.ToSharedRef());
}

void FIndirectTexturePluginEditorModule::ShutdownModule()
{
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;
	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(IndirectTextureActions.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIndirectTexturePluginEditorModule, IndirectTexturePluginEditor)