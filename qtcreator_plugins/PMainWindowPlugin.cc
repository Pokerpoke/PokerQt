#include "gui/PMainWindow.h"
#include "PMainWindowPlugin.h"

#include <QtPlugin>

PMainWindowPlugin::PMainWindowPlugin(QObject *parent) : QObject(parent)
{
}

void PMainWindowPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool PMainWindowPlugin::isInitialized() const
{
    return initialized;
}

QWidget *PMainWindowPlugin::createWidget(QWidget *parent)
{
    return new PMainWindow(parent);
}

QString PMainWindowPlugin::name() const
{
    return QStringLiteral("PMainWindow");
}

QString PMainWindowPlugin::group() const
{
    return QStringLiteral("PokerQt");
}

QIcon PMainWindowPlugin::icon() const
{
    return QIcon();
}

QString PMainWindowPlugin::toolTip() const
{
    return QString();
}

QString PMainWindowPlugin::whatsThis() const
{
    return QString();
}

bool PMainWindowPlugin::isContainer() const
{
    return false;
}

QString PMainWindowPlugin::domXml() const
{
    return QLatin1String(R"(
<ui language="c++">
  <widget class="PMainWindow" name="main_window">
)"
                         R"(
    <property name="geometry">
      <rect>
        <x>0</x>
        <y>0</y>
        <width>100</width>
        <height>100</height>
      </rect>
    </property>
")
R"(
    <property name="toolTip">
      <string>The Poker Qt plugin</string>
    </property>
    <property name="whatsThis">
      <string>The Poker Qt plugin.</string>
    </property>
  </widget>
</ui>
)");
}

QString PMainWindowPlugin::includeFile() const
{
    return QStringLiteral("gui/PMainWindow.h");
}
