#include "ECMatrix.h"
#include <iostream>
#include <cassert>
#include <vector>

int main()
{
    ECMatrix<int> matrix({2, 2}, {2, 4, 6, 8});
    ECMatrix<int> result = matrix+2;

    assert(result({0, 0}) == 4);
    assert(result({0, 1}) == 6);
    assert(result({1, 0}) == 8);
    assert(result({1, 1}) == 10);

    std::cout << result({0,0}) << std::endl;

    return 0;
}