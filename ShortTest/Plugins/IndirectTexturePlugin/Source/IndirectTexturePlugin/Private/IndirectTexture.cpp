// Fill out your copyright notice in the Description page of Project Settings.


#include "IndirectTexture.h"

UIndirectTexture::UIndirectTexture()
{
    TilesetTexture = nullptr;
    TilesetTileCount = FIntPoint(0, 0);
    IndirectTextureResolution = FIntPoint(0, 0);
}
