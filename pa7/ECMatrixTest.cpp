#include "ECMatrix.h"
#include <iostream>
#include <cassert>
#include <vector>

void TestInit() {
    std::vector<unsigned> dimensions = {2, 2};
    std::vector<int> elements = {1, 2, 3, 4};
    ECMatrix<int> matrix(dimensions, elements);

    assert(matrix({0, 0}) == 1);
    assert(matrix({0, 1}) == 2);
    assert(matrix({1, 0}) == 3);
    assert(matrix({1, 1}) == 4);
}

void TestElementAccess() {
    ECMatrix<int> matrix({2, 2}, {1, 2, 3, 4});
    assert(matrix({0, 0}) == 1);
    matrix({0, 0}) = 5;
    assert(matrix({0, 0}) == 5);
}

void TestGetDimension() {
    std::vector<unsigned> dimensions = {2, 3};
    ECMatrix<int> matrix(dimensions, std::vector<int>(6, 0));

    assert(matrix.getDimensions() == dimensions);
}

void TestCopyConstructor() {
    ECMatrix<int> matrix1({2, 2}, {1, 2, 3, 4});
    ECMatrix<int> matrix2 = matrix1;

    assert(matrix2({0, 0}) == 1);
    assert(matrix2({1, 1}) == 4);
}

void TestMoveConstructor() {
    ECMatrix<int> matrix1({2, 2}, {1, 2, 3, 4});
    ECMatrix<int> matrix2 = std::move(matrix1);

    assert(matrix2({0, 0}) == 1);
    assert(matrix2({1, 1}) == 4);
}

void TestMatrixAddition() {
    ECMatrix<int> matrix1({2, 2}, {1, 2, 3, 4});
    ECMatrix<int> matrix2({2, 2}, {5, 6, 7, 8});
    ECMatrix<int> result = matrix1 + matrix2;

    assert(result({0, 0}) == 6);
    assert(result({0, 1}) == 8);
    assert(result({1, 0}) == 10);
    assert(result({1, 1}) == 12);
}

void TestMatrixSubtraction() {
    ECMatrix<int> matrix1({2, 2}, {5, 6, 7, 8});
    ECMatrix<int> matrix2({2, 2}, {1, 2, 3, 4});
    ECMatrix<int> result = matrix1 - matrix2;

    assert(result({0, 0}) == 4);
    assert(result({0, 1}) == 4);
    assert(result({1, 0}) == 4);
    assert(result({1, 1}) == 4);
}

void TestMatrixMultiplication() {
    ECMatrix<int> matrix1({2, 2}, {1, 2, 3, 4});
    ECMatrix<int> matrix2({2, 2}, {2, 0, 1, 2});
    ECMatrix<int> result = matrix1 * matrix2;

    assert(result({0, 0}) == 4);
    assert(result({0, 1}) == 4);
    assert(result({1, 0}) == 10);
    assert(result({1, 1}) == 8);
}

void TestScalarMultiplication() {
    ECMatrix<int> matrix1({2, 2}, {1, 2, 3, 4});
    ECMatrix<int> matrix2({2, 2}, {2, 0, 1, 2});
    ECMatrix<int> result = matrix1 * matrix2;

    assert(result({0, 0}) == 4);
    assert(result({0, 1}) == 4);
    assert(result({1, 0}) == 10);
    assert(result({1, 1}) == 8);
}

void TestScalarDivision() {
    ECMatrix<int> matrix({2, 2}, {2, 4, 6, 8});
    ECMatrix<int> result = matrix / 2;

    assert(result({0, 0}) == 1);
    assert(result({0, 1}) == 2);
    assert(result({1, 0}) == 3);
    assert(result({1, 1}) == 4);
}

int main() {
    TestInit();
    TestElementAccess();
    TestGetDimension();
    TestCopyConstructor();
    TestMoveConstructor();
    TestMatrixAddition();
    TestMatrixSubtraction();
    TestMatrixMultiplication();
    TestScalarMultiplication();
    TestScalarDivision();

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}
