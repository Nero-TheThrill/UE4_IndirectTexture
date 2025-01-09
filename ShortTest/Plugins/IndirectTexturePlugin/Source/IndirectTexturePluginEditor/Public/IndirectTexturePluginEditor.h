// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IndirectTextureActions.h"
#include "Modules/ModuleManager.h"

class FIndirectTexturePluginEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
	TSharedPtr<FIndirectTextureActions> IndirectTextureActions;
};


