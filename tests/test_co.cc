/**
 *
 * Copyright (c) 2021 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2021-10
 * @brief
 *
 * Last Modified:  2022-03-20
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */
#include <coroutine>

#include <tuple>
#include <string>
#include <iostream>

using namespace std;

tuple<string, int> test_func()
{
    return {"lsdkfj", 123};
}

int main(int argc, char const *argv[])
{
    auto [s, i] = test_func();

    cout << s << ":" << i << endl;

    /* code */
    return 0;
}
