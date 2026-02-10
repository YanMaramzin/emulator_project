#include "../include/testreceiver.h"

QString TestReceiver::type() const { return "TestReceiver"; }

void TestReceiver::init(const DeviceConfig &, DeviceContext *ctx) { context = ctx; }

void TestReceiver::start() {
}

void TestReceiver::stop() {
}

void TestReceiver::update(std::chrono::milliseconds) {
}

void TestReceiver::onDataReceived(const QByteArray &data) {
    context->log("Received: " + data);
}
