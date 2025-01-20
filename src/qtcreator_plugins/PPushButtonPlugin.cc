#include "gui/PPushButton.h"
#include "PPushButtonPlugin.h"

#include <QtPlugin>

PPushButtonPlugin::PPushButtonPlugin(QObject *parent) : QObject(parent)
{
}

void PPushButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool PPushButtonPlugin::isInitialized() const
{
    return initialized;
}

QWidget *PPushButtonPlugin::createWidget(QWidget *parent)
{
    return new PPushButton(parent);
}

QString PPushButtonPlugin::name() const
{
    return QStringLiteral("PPushButton");
}

QString PPushButtonPlugin::group() const
{
    return QStringLiteral("PokerQt");
}

QIcon PPushButtonPlugin::icon() const
{
    return QIcon();
}

QString PPushButtonPlugin::toolTip() const
{
    return QString();
}

QString PPushButtonPlugin::whatsThis() const
{
    return QString();
}

bool PPushButtonPlugin::isContainer() const
{
    return false;
}

QString PPushButtonPlugin::domXml() const
{
    return QLatin1String(R"(
<ui language="c++">
  <widget class="PPushButton" name="push_button">
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

QString PPushButtonPlugin::includeFile() const
{
    return QStringLiteral("gui/PPushButton.h");
}
