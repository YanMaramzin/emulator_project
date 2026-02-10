#include "deviceinstance.h"

void DeviceInstance::sendToNetwork(const QByteArray &data) { outgoing.append(data); }

void DeviceInstance::log(const QString &msg) { qDebug() << "[" << m_id << "]" << msg; }

qint64 DeviceInstance::simTimeMs() const { return simTime; }

void DeviceInstance::update(std::chrono::milliseconds dt) {
    simTime += dt.count();
    dev->update(dt);
}

void DeviceInstance::deliver(const QByteArray &data) const { dev->onDataReceived(data); }

QList<QByteArray> DeviceInstance::takeOutgoing() {
    auto tmp = outgoing;
    outgoing.clear();
    return tmp;
}
