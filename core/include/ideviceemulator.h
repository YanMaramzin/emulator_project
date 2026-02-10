#pragma once
#include <QString>
#include <QByteArray>
#include <chrono>
#include <QtPlugin>


class DeviceContext;
struct DeviceConfig;

class IDeviceEmulator
{
public:
    virtual ~IDeviceEmulator() = default;

    virtual QString type() const = 0;
    virtual void init(const DeviceConfig&, DeviceContext*) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void update(std::chrono::milliseconds dt) = 0;
    virtual void onDataReceived(const QByteArray&) = 0;
};

#define IDeviceEmulator_iid "com.radioemu.IDeviceEmulator"
Q_DECLARE_INTERFACE(IDeviceEmulator, IDeviceEmulator_iid)
