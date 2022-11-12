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

#include "HelperFunctions.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <base/Logger.h>

namespace Poker
{
    QString imgPath(const QString &img_name, const QString &skin)
    {
        auto cur_path = QCoreApplication::applicationDirPath();
        auto res = QString("%1/res/img/%2/%3").arg(cur_path).arg(skin).arg(img_name);
        LOG_TRACE << "Load img path " << res;
        return res;
    }

    QString loadCss(const QString &css_name, const QString &skin)
    {
        QString res;
        auto cur_path = QCoreApplication::applicationDirPath();
        auto file_path = QString("%1/res/css/%2/%3").arg(cur_path).arg(skin).arg(css_name);
        QFile f(file_path);
        if (f.open(QFile::ReadOnly))
        {
            LOG_TRACE << "Load style file path " << file_path;
            res = f.readAll();
        }
        else
        {
            LOG_ERROR << "Load style file path " << file_path << " failed";
        }
        return res;
    }
} // namespace Poker
