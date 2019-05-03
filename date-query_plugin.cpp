#include <qtz/widgets/data/date-query.hpp>
#include "date-query_plugin.hpp"

#include <QtCore/QtPlugin>

DateQueryPlugin::DateQueryPlugin(QObject* parent)
    : QObject(parent) {
    m_initialized = false;
    Q_PLUGIN_METADATA(IID "org.ametis.qtz.dateQueryPlugin")
}

void DateQueryPlugin::initialize(QDesignerFormEditorInterface* /* core */) {
    if(m_initialized) {
        return;
    }
    // Add extension registrations, etc. here
    m_initialized = true;
}

bool DateQueryPlugin::isInitialized() const {
    return m_initialized;
}

QWidget* DateQueryPlugin::createWidget(QWidget* parent) {
    return new DateQuery(parent);
}

QString DateQueryPlugin::name() const {
    return QLatin1String("DateQuery");
}

QString DateQueryPlugin::group() const {
    return QLatin1String("Qtz SQL");
}

QIcon DateQueryPlugin::icon() const {
    return QIcon::fromTheme("view-calendar-day",
                            QIcon{":/qtz_plugin/images/date-query.png"});
}

QString DateQueryPlugin::toolTip() const {
    return QLatin1String("Date and time value 'where' clause manipulator");
}

QString DateQueryPlugin::whatsThis() const {
    return QLatin1String("This widget manipulates SQL queries for date and time values.");
}

bool DateQueryPlugin::isContainer() const {
    return false;
}

QString DateQueryPlugin::domXml() const {
    return QLatin1String("<widget class=\"DateQuery\" name=\"dateQuery\">\n</widget>\n");
}

QString DateQueryPlugin::includeFile() const {
    #if defined (Q_OS_LINUX)
    return QLatin1String("/usr/include/qtz/widgets/data/date-query.hpp");
    #elif defined(Q_OS_WIN)
    return QLatin1String("qtz/widgets/data/date-query.hpp");
    #endif
}
