// This file is autogenerated by CMake. Do not edit.

#include <QtQml/qqmlextensionplugin.h>

extern void qml_register_types_ExpertSystem();
Q_GHS_KEEP_REFERENCE(qml_register_types_ExpertSystem)

class ExpertSystemPlugin : public QQmlEngineExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

public:
    ExpertSystemPlugin(QObject *parent = nullptr) : QQmlEngineExtensionPlugin(parent)
    {
        volatile auto registration = &qml_register_types_ExpertSystem;
        Q_UNUSED(registration)
    }
};



#include "ExpertSystemplugin_ExpertSystemPlugin.moc"
