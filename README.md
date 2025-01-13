# Android Sensor Client Plugin for Unreal Engine

Stream data from Android's [Sensor Server](https://github.com/umer0586/SensorServer) straight into Unreal Engine using this plugin.

> [!IMPORTANT]
> Only one sensor is supported at the moment: orientation. However, adding new ones is fairly easy, and the existing one can be used as reference.

# Usage

* Add a `Android Sensor Orientation` component to any of your actor
* Set the device IP and Port in the component's details
* Read the sensor's value from the `Orientation` variable (accessible in Blueprint)

# Compatibility

This has been tested with Unreal Engine 5.5 and SensorServer 6.4.0
