#pragma once
#include "ideviceemulator.h"

class PluginManager {
public:
    static IDeviceEmulator *loadDevice(const QString &type);
};
