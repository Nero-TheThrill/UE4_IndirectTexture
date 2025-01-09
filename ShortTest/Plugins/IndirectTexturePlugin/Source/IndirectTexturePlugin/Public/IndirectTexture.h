// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IndirectTexture.generated.h"
/**
 * 
 */
UCLASS()
class INDIRECTTEXTUREPLUGIN_API UIndirectTexture : public UObject
{
	GENERATED_BODY()
public:
	UIndirectTexture();


	UPROPERTY(EditAnywhere)
	UTexture2D* TilesetTexture;

    UPROPERTY(EditAnywhere)
	FIntPoint TilesetTileCount;

    UPROPERTY(EditAnywhere)
	FIntPoint IndirectTextureResolution;
	UPROPERTY(EditAnywhere)
	UTexture2D* TileIndexTexture;

	void GenerateTileIndexTexture();
	void OnPropertyChanged(UObject* ObjectBeingModified, FPropertyChangedEvent& PropertyChangedEvent);
};
