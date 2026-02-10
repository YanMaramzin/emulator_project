#include "simulatorengine.h"

void SimulatorEngine::addDevice(DeviceInstance *d) { devices.append(d); }

void SimulatorEngine::start() {
    connect(&timer, &QTimer::timeout, this, &SimulatorEngine::tick);
    timer.start(100);
}

void SimulatorEngine::tick() {
    std::chrono::milliseconds dt(100);

    for (auto d : devices)
        d->update(dt);

    QList<QByteArray> packets;
    for (auto d : devices)
        packets.append(d->takeOutgoing());

    for (auto d : devices)
        for (auto& p : packets)
            d->deliver(p);
}
