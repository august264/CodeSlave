// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InGameProjects.generated.h"
#include "GameEmployee.h"







UCLASS()
class CODESLAVE_API AInGameProjects : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInGameProjects();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Project Params", meta = (AllowPrivateAccess = true))
		int Pjct_ID;

	UPROPERTY(EdiyAnyWhere, BlueprintReadWrite, Category = "Project Params", meta = (AllowPrivateAccess = true))
		FString Pjct_Name;

	UPROPERTY(EdiyAnyWhere, BlueprintReadWrite, Category = "Project Params", meta = (AllowPrivateAccess = true))
		float Pjct_Fund;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Project Params", meta = (AllowPrivateAccess = true))
		int Pjct_TimeLength;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Project Params", meta = (AllowPrivateAccess = true))
		TArray<ESkill> RequiredSkills;
};
