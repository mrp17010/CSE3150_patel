#ifndef ECMATRIX_H
#define ECMATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T> 
class ECMatrix {
private:
    std::vector<std::vector<T>> matrix; // Nested vectors to store 2D matrix
    std::vector<unsigned> dimensions; // Vector to store the dimensions

public:
    // Constructor that accepts dimensions and elements
    ECMatrix(const std::vector<unsigned>& _dimensions, const std::vector<T>& elements);

    // // Check if the elements vector matches the specified dimensions
    bool isValidInput(const std::vector<T>& elements) const;

    // // Destructor
    virtual ~ECMatrix();

    // // for reference on noexcept https://en.cppreference.com/w/cpp/language/noexcept_spec
    ECMatrix(const ECMatrix& other); // Copy constructor
    ECMatrix(ECMatrix&& other) noexcept; // Move constructor
    ECMatrix& operator=(const ECMatrix& other); // Copy assignment operator
    ECMatrix& operator=(ECMatrix&& other) noexcept; // Move assignment operator

    // // Access individual elements (Both Required)
    const T& operator()(const std::vector<unsigned>& indices) const; // Only Reads Elements
    T& operator()(const std::vector<unsigned>& indices); // Need another overloaded () operator to modify Elements 

    // // Utility functions
    const std::vector<unsigned>& getDimensions() const;

    // Matrix-Matrix Operations (+/-/*)
    
    template <typename U>
    friend ECMatrix operator+(const ECMatrix& mat1, const ECMatrix& mat2);

    template <typename U>
    friend ECMatrix operator-(const ECMatrix& mat1, const ECMatrix& mat2);

    template <typename U>
    friend ECMatrix operator*(const ECMatrix& mat1, const ECMatrix& mat2);

    // // Scalar Operations

    // template <typename U>
    // friend ECMatrix operator+(const ECMatrix& mat1, const U scalar);

    //reverse scalar operators

};

#include "ECMatrix.cpp" // Include the implementation file
#endif // ECMATRIX_H