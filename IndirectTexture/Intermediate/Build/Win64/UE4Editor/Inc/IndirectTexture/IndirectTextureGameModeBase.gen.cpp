// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IndirectTexture/IndirectTextureGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIndirectTextureGameModeBase() {}
// Cross Module References
	INDIRECTTEXTURE_API UClass* Z_Construct_UClass_AIndirectTextureGameModeBase_NoRegister();
	INDIRECTTEXTURE_API UClass* Z_Construct_UClass_AIndirectTextureGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_IndirectTexture();
// End Cross Module References
	void AIndirectTextureGameModeBase::StaticRegisterNativesAIndirectTextureGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AIndirectTextureGameModeBase_NoRegister()
	{
		return AIndirectTextureGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AIndirectTextureGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AIndirectTextureGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_IndirectTexture,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIndirectTextureGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "IndirectTextureGameModeBase.h" },
		{ "ModuleRelativePath", "IndirectTextureGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AIndirectTextureGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AIndirectTextureGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AIndirectTextureGameModeBase_Statics::ClassParams = {
		&AIndirectTextureGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AIndirectTextureGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AIndirectTextureGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AIndirectTextureGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AIndirectTextureGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AIndirectTextureGameModeBase, 4060809329);
	template<> INDIRECTTEXTURE_API UClass* StaticClass<AIndirectTextureGameModeBase>()
	{
		return AIndirectTextureGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AIndirectTextureGameModeBase(Z_Construct_UClass_AIndirectTextureGameModeBase, &AIndirectTextureGameModeBase::StaticClass, TEXT("/Script/IndirectTexture"), TEXT("AIndirectTextureGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AIndirectTextureGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
