#pragma once

#include "../../../core/include/ideviceemulator.h"
#include "DeviceContext.h"
#include "../../../core/include/deviceconfig.h"
#include <QObject>

class TestTransmitter : public QObject, public IDeviceEmulator {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID IDeviceEmulator_iid)
    Q_INTERFACES(IDeviceEmulator)

public:
    [[nodiscard]] QString type() const override;

    void init(const DeviceConfig &cfg, DeviceContext *ctx) override;

    void start() override;

    void stop() override;

    void update(std::chrono::milliseconds dt) override;

    void onDataReceived(const QByteArray &) override;

private:
    DeviceContext *context = nullptr;
    int interval = 100;
    int acc = 0;
};
