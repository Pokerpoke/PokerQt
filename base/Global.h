/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-06
 * @brief
 *
 * Last Modified:  2022-06-16
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#pragma once

#if defined(POKER_LIBRARY)
#define POKER_EXPORT __declspec(dllexport)
#else
#define POKER_EXPORT __declspec(dllimport)
#endif