#include "../include/testtransmitter.h"

QString TestTransmitter::type() const { return "TestTransmitter"; }

void TestTransmitter::init(const DeviceConfig &cfg, DeviceContext *ctx) {
    context = ctx;
    interval = cfg.params.value("interval_ms", 100).toInt();
}

void TestTransmitter::start() {
}

void TestTransmitter::stop() {
}

void TestTransmitter::update(std::chrono::milliseconds dt) {
    acc += dt.count();
    if (acc >= interval) {
        context->sendToNetwork("PING");
        acc = 0;
    }
}

void TestTransmitter::onDataReceived(const QByteArray &) {
}
