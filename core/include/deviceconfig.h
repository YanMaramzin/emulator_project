#pragma once
#include <QString>
#include <QVariantMap>

struct DeviceConfig
{
    QString id;
    QString pluginType;   // теперь не путь!
    QVariantMap params;
};
