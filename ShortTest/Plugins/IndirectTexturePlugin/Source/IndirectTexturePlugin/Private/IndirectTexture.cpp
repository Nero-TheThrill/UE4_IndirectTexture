// Fill out your copyright notice in the Description page of Project Settings.


#include "IndirectTexture.h"

UIndirectTexture::UIndirectTexture()
{
    TilesetTexture = nullptr;
    TilesetTileCount = FIntPoint(0, 0);
    IndirectTextureResolution = FIntPoint(0, 0);
    FCoreUObjectDelegates::OnObjectPropertyChanged.AddUObject(this, &UIndirectTexture::OnPropertyChanged);
}

void UIndirectTexture::OnPropertyChanged(UObject* ObjectBeingModified, FPropertyChangedEvent& PropertyChangedEvent)
{
    if (ObjectBeingModified == this)
    {
        FName PropertyName = (PropertyChangedEvent.Property != nullptr)
            ? PropertyChangedEvent.Property->GetFName()
            : NAME_None;

        if (PropertyName == GET_MEMBER_NAME_CHECKED(UIndirectTexture, TilesetTexture))
        {
            if (TilesetTexture != nullptr)
            {
                TilesetTileCount = FIntPoint(TilesetTexture->GetSizeX(), TilesetTexture->GetSizeY());
                UE_LOG(LogTemp, Warning, TEXT("size x: %d, size y: %d"), TilesetTexture->GetSizeX(), TilesetTexture->GetSizeY());
            }
            else
            {
                TilesetTileCount = FIntPoint(0,0);
                UE_LOG(LogTemp, Warning, TEXT("texture removed"));
                UE_LOG(LogTemp, Warning, TEXT("size x: %d, size y: %d"), TilesetTileCount.X, TilesetTileCount.Y);
            }
            UE_LOG(LogTemp, Warning, TEXT("virtual texture resolution should be: %d x %d"), IndirectTextureResolution.X * TilesetTileCount.X, IndirectTextureResolution.Y * TilesetTileCount.Y);
        }
    }

}
