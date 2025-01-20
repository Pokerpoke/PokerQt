/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <PokerQt/gui/gui_global.h>
#include <QtCore/QString>

namespace Poker
{
QString POKERQT_GUI_EXPORT imgPath(const QString &img_name, const QString &skin = "default");

QString POKERQT_GUI_EXPORT loadCss(const QString &css_name, const QString &skin = "default");
} // namespace Poker