#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "configloader.h"

std::vector<DeviceConfig> ConfigLoader::load(const QString &path) {
    QFile f(path);
    f.open(QIODevice::ReadOnly);
    auto root = QJsonDocument::fromJson(f.readAll()).object();

    std::vector<DeviceConfig> list;

    for (auto v: root["devices"].toArray()) {
        auto o = v.toObject();
        DeviceConfig c;
        c.id = o["id"].toString();
        c.pluginType = o["plugin"].toString();

        auto params = o["params"].toObject();
        for (auto it = params.begin(); it != params.end(); ++it)
            c.params[it.key()] = it.value().toVariant();

        list.push_back(c);
    }

    return list;
}
