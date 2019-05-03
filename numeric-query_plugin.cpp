#include <qtz/widgets/data/numeric-query.hpp>
#include "numeric-query_plugin.hpp"

#include <QtCore/QtPlugin>

NumericQueryPlugin::NumericQueryPlugin(QObject* parent)
    : QObject(parent) {
    m_initialized = false;
    Q_PLUGIN_METADATA(IID "org.ametis.qtz.numericQueryPlugin")
}

void NumericQueryPlugin::initialize(QDesignerFormEditorInterface* /* core */) {
    if(m_initialized) {
        return;
    }
    // Add extension registrations, etc. here
    m_initialized = true;
}

bool NumericQueryPlugin::isInitialized() const {
    return m_initialized;
}

QWidget* NumericQueryPlugin::createWidget(QWidget* parent) {
    return new NumericQuery(parent);
}

QString NumericQueryPlugin::name() const {
    return QLatin1String("NumericQuery");
}

QString NumericQueryPlugin::group() const {
    return QLatin1String("Qtz SQL");
}

QIcon NumericQueryPlugin::icon() const {
    return QIcon::fromTheme("format-precision-more",
                            QIcon{":/qtz_plugin/images/numeric-query.png"});
}

QString NumericQueryPlugin::toolTip() const {
    return QLatin1String("Numeric value 'where' clause manipulator");
}

QString NumericQueryPlugin::whatsThis() const {
    return QLatin1String("This widget manipulates SQL queries for numeric values.");
}

bool NumericQueryPlugin::isContainer() const {
    return false;
}

QString NumericQueryPlugin::domXml() const {
    return QLatin1String("<widget class=\"NumericQuery\" name=\"numericQuery\">\n</widget>\n");
}

QString NumericQueryPlugin::includeFile() const {
    #if defined (Q_OS_LINUX)
    return QLatin1String("/usr/include/qtz/widgets/data/numeric-query.hpp");
    #elif defined(Q_OS_WIN)
    return QLatin1String("qtz/widgets/data/numeric-query.hpp");
    #endif
}
