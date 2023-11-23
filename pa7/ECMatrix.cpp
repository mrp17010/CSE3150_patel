#include "ECMatrix.h"
using namespace std;

template<typename T>
ECMatrix<T>::ECMatrix(const vector<unsigned>& _dimensions, const vector<T>& elements)
{
    dimensions = _dimensions;
    vector<vector<T>> mymat;

    if(!isValidInput(elements))
    {
        throw invalid_argument("Dimensions don't align");
    }

    int count = 0;
    for(int i = 0; i<dimensions[0]; i++)
    {
        vector<T> cur_row;
        mymat.push_back(cur_row);
        for(int j = 0; j<dimensions[1];j++)
        {
            mymat[i].push_back(elements[count]);
            count++;
        }
    }
    matrix = mymat;
}

template<typename T>
bool ECMatrix<T>::isValidInput(const std::vector<T>& elements) const
{
    if(elements.size() != (dimensions[0]*dimensions[1]))
    {
        return false;
    }
    return true;
}

template<typename T>
ECMatrix<T>::~ECMatrix(){};

template <typename T>
ECMatrix<T>::ECMatrix(const ECMatrix& other): matrix(other.matrix), dimensions(other.dimensions){}

//move contructor 
template <typename T>
ECMatrix<T>::ECMatrix(ECMatrix&& other) noexcept: matrix(move(other.matrix)), dimensions(move(other.dimensions)){}

template <typename T>
ECMatrix<T>& ECMatrix<T>::operator=(const ECMatrix& other)
{
    if (this == &other)
    {
        return *this;
    }
    
    matrix = other.matrix;
    dimensions = other.dimensions;
    return *this;
}

template <typename T>
ECMatrix<T>& ECMatrix<T>::operator=(ECMatrix&& other) noexcept
{
    matrix = move(other.matrix);
    dimensions = move(other.dimensions);
    return *this;
}

template <typename T>
const T& ECMatrix<T>::operator()(const std::vector<unsigned>& indices)const
{
    if(indices.size() != dimensions.size())
    {
        throw out_of_range();
    }

    return matrix[indices[0]][indices[1]];   
}

template <typename T>
T& ECMatrix<T>::operator()(const std::vector<unsigned>& indices)
{
    if(indices.size() != dimensions.size())
    {
        throw out_of_range();
    }

    return matrix[indices[0]][indices[1]];
}

template <typename T>
const vector<unsigned>& ECMatrix<T>::getDimensions()const
{
    return dimensions;
}

template <typename U>
ECMatrix<U> operator+(const ECMatrix<U>& mat1, const ECMatrix<U> mat2)
{
    vector<unsigned> mat1_d = mat1.getDimensions();
    vector<unsigned> mat2_d = mat2.getDimensions();

    if(mat1_d != mat2_d)
    {
        throw invalid_argument("Dimensions must be the same for addition!");
    }
    vector<U> newelements;

    for(unsigned i = 0; i<mat1_d[0]; i++)
    {
        for(unsigned j = 0; j<mat1_d[1];j++)
        {
            U value = mat1({i, j}) + mat2({i , j});
            newelements.push_back(value);
        }
    }
    ECMatrix<U> newmatrix(mat1_d, newelements);
    return newmatrix;
}

template <typename U>
ECMatrix<U> operator-(const ECMatrix<U>& mat1, const ECMatrix<U> mat2)
{
    vector<unsigned> mat1_d = mat1.getDimensions();
    vector<unsigned> mat2_d = mat2.getDimensions();

    if(mat1_d != mat2_d)
    {
        throw invalid_argument("Dimensions must be the same for subtraction!");
    }
    vector<U> newelements;

    for(unsigned i = 0; i<mat1_d[0]; i++)
    {
        for(unsigned j = 0; j<mat1_d[1];j++)
        {
            U value = mat1({i, j}) - mat2({i , j});
            newelements.push_back(value);
        }
    }
    ECMatrix<U> newmatrix(mat1_d, newelements);
    return newmatrix;
}

template <typename U>
ECMatrix<U> operator*(const ECMatrix<U>& mat1, const ECMatrix<U> mat2)
{
    vector<unsigned> mat1_d = mat1.getDimensions();
    vector<unsigned> mat2_d = mat2.getDimensions();

    if(mat1_d[1] != mat2_d[0])
    {
        throw invalid_argument("Dimensions aren't aligned for matrix multiplication!");
    }
    vector<U> newelements;

    for(unsigned i = 0; i<mat1_d[0]; i++)
    {
        U cur_val = 0;
        for(unsigned j = 0; j<mat2_d[1];j++)
        {
            for(unsigned k = 0; k<mat2_d[0];k++)
            {
                cur_val += (mat1({i, k}) * mat2({k, j}));
            }
            newelements.push_back(cur_val);
            cur_val = 0;
        }
    }
    ECMatrix<U> newmatrix({mat1_d[0],mat2_d[1]}, newelements);
    return newmatrix;
}




