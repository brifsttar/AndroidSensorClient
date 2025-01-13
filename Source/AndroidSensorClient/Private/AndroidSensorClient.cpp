#include "AndroidSensorClient.h"

#define LOCTEXT_NAMESPACE "FAndroidSensorClientModule"

DEFINE_LOG_CATEGORY(LogAndroidSensorClient);

void FAndroidSensorClientModule::StartupModule() {
}

void FAndroidSensorClientModule::ShutdownModule() {

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAndroidSensorClientModule, AndroidSensorClient)
