/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-02-22
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <vector>
#include <iostream>

#include "base/Singleton.h"
#include "base/Logger.h"

using namespace Poker::base;
using namespace std;

int main(int argc, char const *argv[])
{
    Singleton<std::vector<int>>::instance().push_back(1);
    cout << Singleton<std::vector<int>>::instance().at(0) << endl;

    LOG_DEBUG << Singleton<std::vector<int>>::instance().at(0);
    return 0;
}
