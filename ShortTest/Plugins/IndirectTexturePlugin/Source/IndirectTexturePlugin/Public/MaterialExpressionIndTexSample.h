// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpression.h"
#include "IndirectTexture.h"
#include "MaterialExpressionIndTexSample.generated.h"

/**
 * 
 */
UCLASS()
class INDIRECTTEXTUREPLUGIN_API UMaterialExpressionIndTexSample : public UMaterialExpression
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	class UIndirectTexture* IndirectTexture;
	virtual int32 Compile(FMaterialCompiler* Compiler, int32 OutputIndex) override;
	virtual UObject* GetReferencedTexture() const override;
	virtual bool CanReferenceTexture() const override;
};
