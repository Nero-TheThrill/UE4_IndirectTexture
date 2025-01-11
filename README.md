# Indirect Texture

This feature allows you to render a huge texture while using minimal  memory.

## Overview
 **Tileset Texture** is a texture composed of **Tiles**
 
 We create an **Index Texture** that contains **random index** (0 to Max Tile Counts-1)
 
 Each **Index** in the Index Texture specifies which **Tile** in the Tileset Texture should be used for the resulting texture
 
 The Index Texture data is read using the default UV mapping
 
 Based on this data, a UV is generated relative to the Tileset Texture
 
With this approach, we use only the memory size of the **Index Texture**, but we can render a texture with a size equivalent to **Index Texture Size** × **Tile Size**
 

## How to Test Result

1. Open **ShortTest.uproject**

2. Then open **TestScene**

3. **PUBGTile** folder contains *provided texture*, *Indirect Texture Data asset*, and *Material* 

4. You won't see the result at first, because the **Tile Index Texture** isn't created yet

    <img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/guideline1.png" width="300"/>

5. To create **Tile Index Texture**, open **PUBGIndTex**(Indirect Texture Asset)

    <img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/guideline2.png" width="300"/>

6.  **Tile Index Texture** will be created if you modify either **Tile count** or **Index Texture Resolution** (If you created *Tile Index Texture* properly, you'll see the created texture)

    <img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/guideline3.png" width="300"/>

5. Save it, then go to **Material**

6. Just replace the link in the same way(Somehow it won't update automatically if you don't modify link) and Save it

    <img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/guideline4.png" width="300"/>  ⇒  <img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/guideline5.png" width="300"/>

7. You'll see the result now

###  Test Other Cases
    If you want to test other cases like changing Tile count or Index Texture Resolution, follow <How to Test Result> 5. ~ 6.





## Results


<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/result1.png"  width="300"/>  

TileCount: (4,4) IndirectTextureResolution: (8,16)  

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/result2.png"  width="300"/>

TileCount: (8,8) IndirectTextureResolution: (8,16)

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/result3.png"  width="300"/>

TileCount: (4,4) IndirectTextureResolution: (32,64)

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/result4.png"  width="300"/>

TileCount: (8,8) IndirectTextureResolution: (8,8)

 
## Key Formula

$$
\frac{IndexTexture.xy}{TileCount.xy} + (\frac{(VirtualTextureSize.xy*UV) \mod TileSize.xy}{TileSize.xy} \times \frac{1}{TileCount.xy})
$$

### Breakdown

--------

### $IndexTexture.xy$ 

* Has x,y values which indicates the tile index. Calculated and stored in IndexTexture at compile time

* $IndexTexture.xy = (RandomTileIndex \mod TileCount.x, \frac{RandomTileIndex}{TileCount.x})$

--------

### $\frac{IndexTexture.xy}{TileCount.xy}$ 

* Indicates each **Tile**'s TopLeft UV. 

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/tiletopleft.png" width="600"/>

*  Now we need **offset** value which will be added into TopLeft UV

--------

### ${(VirtualTextureSize.xy*UV) \mod TileSize.xy} $

* $(VirtualTextureSize.xy*UV)$ gives the pixel coordinate from virtual texture(which doesn't actually exist) of corresponding UV

* $\mod TileSize.xy$ help us to map values $0$ to $TileSize.xy$

--------

### $(\frac{(VirtualTextureSize.xy*UV) \mod TileSize.xy}{TileSize.xy} )$

* We need final UVs to use for Tileset Texture at the end

* Currently values are between  $0$ to $TileSize.xy$. So we divide value by $TileSize.xy$

* By this division, values will be mapped between $0$ to $1$

--------

### $(\frac{(VirtualTextureSize.xy*UV) \mod TileSize.xy}{TileSize.xy} \times \frac{1}{TileCount.xy})$

* But we don't want the whole tileset texture to be rendered per tile

* We only need a single **Tile** per **Index Texture Pixel**

* So we divide value with ${TileCount.xy}$ 

* Now we can use this for the **offset** value

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/uv01.png" width="600"/>

## FYI


I noticed there is discontinuity in UV mapping between tiles at first

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/discontinuity.png" width="300"/>


It seemed like large UV gap between tiles causing this. So I did a modification to both Material and Texture.

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/mipmap0.png" width="300"/> 

First, I set the texture to use alaways mip level 0 which is full resolution.

<img src="https://github.com/Nero-TheThrill/UE4_IndirectTexture/blob/main/MD_IMG/filter.png" width="300"/>

Also changed tileset texture filter to Nearest. Which will pick the nearest texel(means it doesn't mixing color)