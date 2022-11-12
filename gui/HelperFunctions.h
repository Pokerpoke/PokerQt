/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-11-12
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include "base/Global.h"
#include <QtCore/QString>

namespace Poker
{
    QString POKER_EXPORT imgPath(const QString &img_name, const QString &skin = "default");

    QString POKER_EXPORT loadCss(const QString &css_name, const QString &skin = "default");
} // namespace Poker