/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#pragma once

#ifdef WIN32
#if defined(POKERQT_GUI_LIB)
#define POKERQT_GUI_EXPORT __declspec(dllexport)
#else
#define POKERQT_GUI_EXPORT __declspec(dllimport)
#endif
#else
#define POKERQT_GUI_EXPORT
#endif // WIN32