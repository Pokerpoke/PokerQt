/**
 *
 * Copyright (c) 2025 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2025-01
 * @brief
 *
 * Last Modified:  2025-01-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#pragma once

#include <memory>
#include <any>
#include <PokerQt/base/base_global.h>

namespace Poker::base
{
class MessagePrivate;

class POKERQT_BASE_EXPORT Message
{
public:
    Message();
    ~Message();
    int id();
    void set_id(int id);
    void setData(const std::any &data);
    std::any data();

private:
    std::shared_ptr<MessagePrivate> d;
};
} // namespace Poker::base