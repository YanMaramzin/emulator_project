#include <QCoreApplication>
#include <QDebug>
#include <simulatorengine.h>
#include <pluginmanager.h>
#include <deviceinstance.h>
#include <configloader.h>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    if (argc < 2) {
        qCritical() << "Usage:" << argv[0] << "config.json";
        return 1;
    }

    QString configPath = argv[1];
    std::vector<DeviceConfig> deviceConfigs;

    try {
        deviceConfigs = ConfigLoader::load(configPath);
    } catch (const std::exception &e) {
        qCritical() << "Failed to load config:" << e.what();
        return 1;
    }

    SimulatorEngine engine;

    // Создаём устройства по конфигу
    for (const auto &cfg: deviceConfigs) {
        auto plugin = PluginManager::loadDevice(cfg.pluginType);
        if (!plugin) {
            qWarning() << "Cannot load plugin type:" << cfg.pluginType;
            continue;
        }

        // Создаём экземпляр устройства и передаём контекст ядра
        auto instance = new DeviceInstance(plugin, cfg.id);

        plugin->init(cfg, instance); // init с DeviceConfig и DeviceContext*

        engine.addDevice(instance);
    }

    // Старт симуляции
    engine.start();

    qDebug() << "Simulation started. Press Ctrl+C to exit.";
    return app.exec();
}
