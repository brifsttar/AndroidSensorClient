#pragma once

#include "CoreMinimal.h"
#include "AndroidSensorReader.h"
#include "AndroidSensorOrientation.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (AndroidSenvorClient), meta = (BlueprintSpawnableComponent))
class ANDROIDSENSORCLIENT_API UAndroidSensorOrientation : public UAndroidSensorReader
{
	GENERATED_BODY()

protected:
	virtual FString GetSensorPath() override;
	virtual void ParseValues(const TArray<TSharedPtr<FJsonValue>>& Values) override;

public:
	UPROPERTY(BlueprintReadOnly, Category = "Android Sensor Client")
	FVector Orientation;
};
