#pragma once
#include <vector>
#include "deviceconfig.h"

class ConfigLoader
{
public:
    static std::vector<DeviceConfig> load(const QString& path);
};
