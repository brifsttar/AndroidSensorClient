#include "AndroidSensorOrientation.h"

FString UAndroidSensorOrientation::GetSensorPath() {
	return TEXT("sensor/connect?type=android.sensor.orientation");
}

void UAndroidSensorOrientation::ParseValues(const TArray<TSharedPtr<FJsonValue>>& Values) {
	Orientation.X = Values[0]->AsNumber();
	Orientation.Y = Values[1]->AsNumber();
	Orientation.Z = Values[2]->AsNumber();
}
