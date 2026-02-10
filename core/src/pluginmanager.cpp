#include <QCoreApplication>
#include <QDir>
#include <QPluginLoader>
#include <QLibrary>
#include <QDebug>
#include "pluginmanager.h"

IDeviceEmulator * PluginManager::loadDevice(const QString &type) {
    QDir dir(qApp->applicationDirPath() + "/plugins");

    for (const QString &file: dir.entryList(QDir::Files)) {
        QString path = dir.absoluteFilePath(file);
        if (!QLibrary::isLibrary(path))
            continue;

        QPluginLoader loader(path);

        if (!loader.load()) {
            qWarning() << "Plugin load error:" << loader.errorString();
            return nullptr;
        }

        QObject* obj = loader.instance();
        if (!obj) {
            qWarning() << "Instance error:" << loader.errorString();
            return nullptr;
        }

        auto dev = qobject_cast<IDeviceEmulator *>(obj);
        if (dev && dev->type() == type)
            return dev;
    }

    qWarning() << "Plugin type not found:" << type;
    return nullptr;
}
