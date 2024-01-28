#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    private:
        float data[10][10];
        int size;

    public:
        Matrix();
        Matrix(const int);
        void fillRandom();
        Matrix operator*(const Matrix&) const;
        Matrix operator+(const Matrix&) const;
        void print() const;
};
#endif // MATRIX_H
