#include "gui/PTitleBar.h"
#include "PTitleBarPlugin.h"

#include <QtPlugin>

PTitleBarPlugin::PTitleBarPlugin(QObject *parent) : QObject(parent)
{
}

void PTitleBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool PTitleBarPlugin::isInitialized() const
{
    return initialized;
}

QWidget *PTitleBarPlugin::createWidget(QWidget *parent)
{
    return new PTitleBar(parent);
}

QString PTitleBarPlugin::name() const
{
    return QStringLiteral("PTitleBar");
}

QString PTitleBarPlugin::group() const
{
    return QStringLiteral("PokerQt");
}

QIcon PTitleBarPlugin::icon() const
{
    return QIcon();
}

QString PTitleBarPlugin::toolTip() const
{
    return QString();
}

QString PTitleBarPlugin::whatsThis() const
{
    return QString();
}

bool PTitleBarPlugin::isContainer() const
{
    return false;
}

QString PTitleBarPlugin::domXml() const
{
    return QLatin1String(R"(
<ui language="c++">
  <widget class="PTitleBar" name="title_bar">
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

QString PTitleBarPlugin::includeFile() const
{
    return QStringLiteral("gui/PTitleBar.h");
}
