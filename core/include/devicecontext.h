#pragma once
#include <QByteArray>
#include <QString>

class DeviceContext
{
public:
    virtual ~DeviceContext() = default;
    virtual void sendToNetwork(const QByteArray& data) = 0;
    virtual void log(const QString& msg) = 0;
    virtual qint64 simTimeMs() const = 0;
};
