#pragma once
#include "IDeviceEmulator.h"
#include "DeviceContext.h"
#include "DeviceConfig.h"
#include <QObject>

class TestReceiver : public QObject, public IDeviceEmulator {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID IDeviceEmulator_iid)
    Q_INTERFACES(IDeviceEmulator)

public:
    [[nodiscard]] QString type() const override;

    void init(const DeviceConfig &, DeviceContext *ctx) override;

    void start() override;

    void stop() override;

    void update(std::chrono::milliseconds) override;

    void onDataReceived(const QByteArray &data) override;

private:
    DeviceContext *context = nullptr;
};
