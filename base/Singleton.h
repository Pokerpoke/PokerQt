/**
 * 
 * Copyright (c) 2021 Pokerpoke
 * 
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief    
 * 
 * Last Modified:  2021-10-06
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 * 
 */

namespace Poker
{
    template <typename T>
    class Singleton
    {
    public:
        static T &instance()
        {
            static T t;
            return t;
        }

    private:
        Singleton() = default;
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton) = delete;
    };
}