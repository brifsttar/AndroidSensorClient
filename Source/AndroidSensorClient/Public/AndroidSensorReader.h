#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include "AndroidSensorReader.generated.h"


UCLASS(Abstract)
class ANDROIDSENSORCLIENT_API UAndroidSensorReader : public UActorComponent
{
	GENERATED_BODY()

private:
	TSharedPtr<IWebSocket> Socket;
	TSharedPtr<FJsonValue> JsonValue;

	void ReceiveOnMessage(const FString& Message);
	void ReceiveOnConnected();
	void ReceiveOnClosed(int32 StatusCode, const FString& Reason, bool bWasClean);
	void ReceiveOnError(const FString& Error);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Android Sensor Client")
	FString ServerUrl = TEXT("192.168.0.1:8080");

	UAndroidSensorReader();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// To implement by child classes
	virtual FString GetSensorPath();
	virtual void ParseValues(const TArray<TSharedPtr<FJsonValue>>& Values);
	
};
