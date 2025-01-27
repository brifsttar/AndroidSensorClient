#include "AndroidSensorReader.h"
#include "Serialization/JsonSerializer.h"


UAndroidSensorReader::UAndroidSensorReader() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UAndroidSensorReader::BeginPlay() {
	Super::BeginPlay();
	FString Url = TEXT("ws://") + ServerUrl + TEXT("/") + GetSensorPath();
	Socket = FWebSocketsModule::Get().CreateWebSocket(Url, TEXT("ws"));
	Socket->OnMessage().AddUObject(this, &UAndroidSensorReader::ReceiveOnMessage);
	Socket->OnConnected().AddUObject(this, &UAndroidSensorReader::ReceiveOnConnected);
	Socket->OnClosed().AddUObject(this, &UAndroidSensorReader::ReceiveOnClosed);
	Socket->OnConnectionError().AddUObject(this, &UAndroidSensorReader::ReceiveOnError);
	Socket->Connect();
}

void UAndroidSensorReader::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	if (Socket != nullptr) {
		Socket->Close();
	}
}

FString UAndroidSensorReader::GetSensorPath() {
	return FString();
}

void UAndroidSensorReader::ParseValues(const TArray<TSharedPtr<FJsonValue>>& Values) {
}

void UAndroidSensorReader::ReceiveOnMessage(const FString& Message) {
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Message);
	if (FJsonSerializer::Deserialize(Reader, JsonValue)) {
		ParseValues(JsonValue->AsObject()->GetArrayField("values"));
	}
}

void UAndroidSensorReader::ReceiveOnConnected() {
	UE_LOG(LogAndroidSensorClient, Log, TEXT("Connected"));
}

void UAndroidSensorReader::ReceiveOnClosed(int32 StatusCode, const FString& Reason, bool bWasClean) {
	UE_LOG(LogAndroidSensorClient, Warning, TEXT("Connection closed: %s"), *Reason);
}

void UAndroidSensorReader::ReceiveOnError(const FString& Error) {
	UE_LOG(LogAndroidSensorClient, Error, TEXT("%s"), *Error);
}
