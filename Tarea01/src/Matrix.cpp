#include "Matrix.h"

#include <iostream>
#include <iomanip>
#include <random>

Matrix::Matrix(){}

Matrix::Matrix(const int size):size(size){}

void Matrix::fillRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-100, 100);

    for(int i=0; i<size; i++)
        {
            for (int j=0; j<size; j++)
            {
                data[i][j] = dist(gen);
            }
        }
}

Matrix Matrix::operator*(const Matrix& other) const
{
    Matrix result(size);

    for (int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                float sum=0.0;
                for (int k=0; k<size; k++)
                {
                    sum += data[i][k]*other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix result(size);
    for(int i=0; i<size; i++)
        {
            for (int j= 0; j<size; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
}

void Matrix::print() const
{
    for (int i=0; i<size; i++)
        {
            for (int j=0; j<size; j++)
            {
                std::cout<<std::fixed<<std::setprecision(2)<<data[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }
}
