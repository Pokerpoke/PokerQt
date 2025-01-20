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

#include "HelperFunctions.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <PokerQt/base/Logger.h>

namespace Poker
{
QString imgPath(const QString &img_name, const QString &skin)
{
    auto cur_path = QCoreApplication::applicationDirPath();
    auto res      = QString("%1/res/img/%2/%3").arg(cur_path).arg(skin).arg(img_name);
    spdlog::trace("Load img path {}", res.toStdString());
    return res;
}

QString loadCss(const QString &css_name, const QString &skin)
{
    QString res;
    auto cur_path  = QCoreApplication::applicationDirPath();
    auto file_path = QString("%1/res/css/%2/%3").arg(cur_path).arg(skin).arg(css_name);
    QFile f(file_path);
    if (f.open(QFile::ReadOnly))
    {
        spdlog::trace("Load style file path {}", file_path.toStdString());
        res = f.readAll();
    }
    else
    {
        spdlog::error("Load style file path {} failed", file_path.toStdString());
    }
    return res;
}
} // namespace Poker
