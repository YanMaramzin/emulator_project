#pragma once
#include <QObject>
#include <QTimer>
#include "deviceinstance.h"

class SimulatorEngine : public QObject
{
    Q_OBJECT
public:
    void addDevice(DeviceInstance* d);

    void start();

private slots:
    void tick();

private:
    QList<DeviceInstance*> devices;
    QTimer timer;
};
