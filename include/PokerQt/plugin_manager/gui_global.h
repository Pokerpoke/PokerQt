/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2025-01-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#pragma once

#ifdef WIN32
#if defined(PLUGIN_MANAGER_LIB)
#define PLUGIN_MANAGER_EXPORT __declspec(dllexport)
#else
#define PLUGIN_MANAGER_EXPORT __declspec(dllimport)
#endif
#else
#define PLUGIN_MANAGER_EXPORT
#endif // WIN32