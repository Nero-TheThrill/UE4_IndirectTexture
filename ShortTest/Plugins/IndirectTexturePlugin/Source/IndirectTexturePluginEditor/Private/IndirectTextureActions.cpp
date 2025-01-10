// Fill out your copyright notice in the Description page of Project Settings.


#include "IndirectTextureActions.h"

#include "IndirectTexture.h"
UClass* FIndirectTextureActions::GetSupportedClass() const
{
    return UIndirectTexture::StaticClass();
}

FText FIndirectTextureActions::GetName() const
{
    return INVTEXT("Indirect Texture");
}

FColor FIndirectTextureActions::GetTypeColor() const
{
    return FColor::Cyan;
}

uint32 FIndirectTextureActions::GetCategories()
{
    return EAssetTypeCategories::Misc;
}