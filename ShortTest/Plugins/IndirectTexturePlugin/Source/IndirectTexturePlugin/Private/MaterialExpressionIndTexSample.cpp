// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialExpressionIndTexSample.h"
#include "MaterialCompiler.h"
#include "Engine/Texture2D.h"
int32 UMaterialExpressionIndTexSample::Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
    if (IndirectTexture&& IndirectTexture->TilesetTexture)
    {
        int32 TextureIndex = Compiler->Texture(IndirectTexture->TilesetTexture, EMaterialSamplerType::SAMPLERTYPE_Color);
        int32 UVIndex = Compiler->TextureCoordinate(0,false,false);

        return Compiler->TextureSample(TextureIndex, UVIndex, EMaterialSamplerType::SAMPLERTYPE_Color);
    }

    // Handle the case where no texture is set
    return Compiler->Error(TEXT("No indirect texture assigned"));
}

UObject* UMaterialExpressionIndTexSample::GetReferencedTexture() const
{
    if (IndirectTexture!=nullptr)
		return IndirectTexture->TilesetTexture;
    return nullptr;
}

bool UMaterialExpressionIndTexSample::CanReferenceTexture() const
{
   if (IndirectTexture != nullptr)
		return IndirectTexture->TilesetTexture != nullptr;
    return false;
}


