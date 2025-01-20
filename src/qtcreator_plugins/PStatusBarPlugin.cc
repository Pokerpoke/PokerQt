#include "gui/PStatusBar.h"
#include "PStatusBarPlugin.h"

#include <QtPlugin>

PStatusBarPlugin::PStatusBarPlugin(QObject *parent) : QObject(parent)
{
}

void PStatusBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool PStatusBarPlugin::isInitialized() const
{
    return initialized;
}

QWidget *PStatusBarPlugin::createWidget(QWidget *parent)
{
    return new PStatusBar(parent);
}

QString PStatusBarPlugin::name() const
{
    return QStringLiteral("PStatusBar");
}

QString PStatusBarPlugin::group() const
{
    return QStringLiteral("PokerQt");
}

QIcon PStatusBarPlugin::icon() const
{
    return QIcon();
}

QString PStatusBarPlugin::toolTip() const
{
    return QString();
}

QString PStatusBarPlugin::whatsThis() const
{
    return QString();
}

bool PStatusBarPlugin::isContainer() const
{
    return false;
}

QString PStatusBarPlugin::domXml() const
{
    return QLatin1String(R"(
<ui language="c++">
  <widget class="PStatusBar" name="status_bar">
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

QString PStatusBarPlugin::includeFile() const
{
    return QStringLiteral("gui/PStatusBar.h");
}
