// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialExpressionIndTexSample.h"
#include "MaterialCompiler.h"
#include "Engine/Texture2D.h"
int32 UMaterialExpressionIndTexSample::Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
    if (IndirectTexture&& IndirectTexture->TileIndexTexture)
    {
		int32 TileCountX = Compiler->Constant(IndirectTexture->TilesetTileCount.X);
		int32 TileCountY = Compiler->Constant(IndirectTexture->TilesetTileCount.Y);
		int32 IndirectTexResX = Compiler->Constant(IndirectTexture->IndirectTextureResolution.X);
		int32 IndirectTexResY = Compiler->Constant(IndirectTexture->IndirectTextureResolution.Y);
		int32 TileSizeX = Compiler->Constant(IndirectTexture->TilesetTexture->GetSizeX() / IndirectTexture->TilesetTileCount.X);
		int32 TileSizeY = Compiler->Constant(IndirectTexture->TilesetTexture->GetSizeY() / IndirectTexture->TilesetTileCount.Y);
		int32 VTextureSizeX = Compiler->Mul(TileSizeX, IndirectTexResX);
		int32 VTextureSizeY = Compiler->Mul(TileSizeY, IndirectTexResY);

		int32 UV = Compiler->TextureCoordinate(0, false, false);
		int32 UV_X = Compiler->ComponentMask(UV, true, false, false, false);
		int32 UV_Y = Compiler->ComponentMask(UV, false, true, false, false);

		int32 VirtualUV_X = Compiler->Mul(VTextureSizeX, UV_X);
		int32 VirtualUV_Y = Compiler->Mul(VTextureSizeY, UV_Y);

		int32 IndexTexture = Compiler->Texture(IndirectTexture->TileIndexTexture, EMaterialSamplerType::SAMPLERTYPE_Color);
		int32 Index = Compiler->TextureSample(IndexTexture, UV, EMaterialSamplerType::SAMPLERTYPE_Color);
		int32 IndexX = Compiler->ComponentMask(Index, true, false, false, false);
		int32 IndexY = Compiler->ComponentMask(Index, false, true, false, false);

		IndexX = Compiler->Mul(IndexX, Compiler->Constant(255));
		IndexY = Compiler->Mul(IndexY, Compiler->Constant(255));

		IndexX = Compiler->Div(IndexX, TileCountX);
		IndexY = Compiler->Div(IndexY, TileCountY);


		int32 TileUV_X = Compiler->Fmod(VirtualUV_X, TileSizeX);
		int32 TileUV_Y = Compiler->Fmod(VirtualUV_Y, TileSizeY);

		TileUV_X = Compiler->Div(TileUV_X, TileSizeX);
		TileUV_Y = Compiler->Div(TileUV_Y, TileSizeY);

		TileUV_X = Compiler->Div(TileUV_X, TileCountX);
		TileUV_Y = Compiler->Div(TileUV_Y, TileCountY);



		int32 ResultUV_X = Compiler->Add(TileUV_X, IndexX);
		int32 ResultUV_Y = Compiler->Add(TileUV_Y, IndexY);


		int32 ResultUV = Compiler->AppendVector(ResultUV_X, ResultUV_Y);
    	
		return ResultUV;
    }

    return Compiler->Error(TEXT("No indirect texture assigned"));
}

UObject* UMaterialExpressionIndTexSample::GetReferencedTexture() const
{
    if (IndirectTexture!=nullptr)
		return IndirectTexture->TileIndexTexture;
    return nullptr;
}

bool UMaterialExpressionIndTexSample::CanReferenceTexture() const
{
   if (IndirectTexture != nullptr)
		return IndirectTexture->TileIndexTexture != nullptr;
    return false;
}


