#pragma once
#include <QList>
#include <QDebug>
#include "devicecontext.h"
#include "ideviceemulator.h"

class DeviceInstance : public DeviceContext
{
public:
    DeviceInstance(IDeviceEmulator* d, QString id) : dev(d), m_id(id) {}

    void sendToNetwork(const QByteArray& data) override;

    void log(const QString& msg) override;

    qint64 simTimeMs() const override;

    void update(std::chrono::milliseconds dt);

    void deliver(const QByteArray& data) const;

    QList<QByteArray> takeOutgoing();

private:
    IDeviceEmulator* dev;
    QString m_id;
    qint64 simTime = 0;
    QList<QByteArray> outgoing;
};
