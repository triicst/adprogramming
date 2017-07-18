
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>

#include "Matrix.hpp"

using namespace std;

/*
 * Klasa macierzy - dwuwymiarowa
 *
 * Matrix create in default 3x3
 *
 * Functions:
 *      - Set Data (Specific number, Random values, String of data)
 *      - Change sign of Matrix for opposite (example: -A)
 *      - Add (A+B, A+=B)
 *      - Subtract (ex: A-B, A-=B)
 *      - Multiply (ex: A*B, 3*A, A*3, A*2.563 etc.)
 *      - Power (ex: A^6, A^-1, A^0)
 *      - Transpose the Matrix (ex: A.transpose() )
 *      - Inverse the Matrix (ex: A^-1)
 *      - Calculate determinant of the Matrix
 *      - Calculate moda of the Matrix
 */

/*
 * Constructors & Destructors
 */

/* TODO !
 * Create Matrix with data
 *
 * Note!!! Always end with semicolon ;
 * Format: 1,3.5,-4;300,200,33;0,-2.5,2323.5;
 */
/*
Matrix::Matrix(string inputData)
{
    int comaCounter=0, semicolonCounter=0;

    removeWhiteCharacters(inputData);
    vector<double> vect;

    stringstream ss(inputData);

    int i;
    while(ss>>i)
    {
        vect.push_back(i);
        if(ss.peek() == ';')
            ss.ignore();
    }

    allocateArrays();
    setData(1);
}
*/

// Matrix fix col and rows filed with zeros default
Matrix::Matrix(int r, int c)
:rows(r), cols(c)
{
    allocateArrays();
    setData(0);
}

// Default Matrix 3x3 filled with zeros default
Matrix::Matrix(void)
:rows(3), cols(3)
{
    allocateArrays();
    setData(0);
}

Matrix::Matrix(const Matrix &m)
:rows(m.rows), cols(m.cols)
{
    allocateArrays();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            data[i][j] = m.data[i][j];
}

Matrix::~Matrix(void)
{
    for (int i=0; i<rows; i++) {
        delete [] data[i];
    }
    delete [] data;
}

/**
 * Functions
 */
// Public ----------------------------------------------------------------------

/*
 * Retrun true is number is even else false
 * ex: 2, 6, 124, 10000000 = true
 */
bool isEvenNumber(const int &number)
{
    if(number % 2 == 0)
        return true;
    else
        return false;
}

/*
 * Retrun true if number is below zero (negative) else false
 */
bool isNegativeNumber(const float &number)
{
    if(number<0)
        return true;
    else
        return false;
}

/*
 * Return value of the last element with the highest value
 */
double Matrix::highestValue()
{
    double result = data[0][0];
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            if(result <= data[i][j])
                result = data[i][j];
    return result;
}

/*
 * Return bool if size of matrices are equal
 */
bool isMatrixSizeEqual(const Matrix &m, const Matrix &n)
{
    if(m.rows == n.rows && m.cols == n.cols)
        return true;
    return false;
}

/*
 * Return bool if Columns of matrix 1 equal Rows of matrix 2
 */
bool isColsMatrix1EqualRowsMatrix2(const Matrix m, const Matrix n)
{
    if (m.cols == n.rows)
        return true;
    return false;
}

/*
 * Return bool if matrix is square
 */
bool isMatrixSquare(const Matrix &m)
{
    if (m.rows == m.cols)
        return true;
    return false;
}

/*
bool Matrix::isInteger(const string &s)s
{
    boost::regex integer("(\\+|-)?[[:digit:]]+");

    if( boost::regex_match(s, integer) )
        return true;
    else
        return false;
}
*/
void Matrix::setData(double number)
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            data[i][j] = number;
}

/*
 * TODO
 * To fix:
 *      - double numbers are not recognise
 */
void Matrix::setData(string inputData)
{
    // a11, a12, a13; a21, a22, a23; a31, a32, a33;
    // ? sprawdzenie czy wartości sa liczbami
    // ! sprawdzenie czy ilość wartości się zgadzą (wiersze i kolumny)

    // usunięcie białych znaków
    removeWhiteCharacters(inputData);

    vector<int> vect;
    stringstream ss(inputData);

    int i;
    while(ss>>i)
    {
        vect.push_back(i);
        if(ss.peek() == ',')
            ss.ignore();
    }

    // check if number of data equal Matrix cells
    if(cols*rows != vect.size())
        throw "The number of fields in the matrix does not coincide with the amount of input data";

    int r=0;
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
        {
            data[i][j] = vect[r];
            r++;
        }
}

void Matrix::setDataRandomNumbers()
{
    srand(time(NULL));
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            data[i][j] = (rand()%899 + 100);
}

/*
 * Return value of cell in the Matrix
 * ex:  for matrix 3x3 options are between 1,1 to 3,3
 */
double &Matrix::operator()(int row, int col)
{
    row-=1; col-=1;
    if(row>=this->rows || row<0)
        throw "Can not find the desired row";
    if(col>=this->cols || col<0)
        throw "Can not find the desired column";
    return data[row][col];
}

Matrix &Matrix::operator=(const Matrix &m)
{
    // avoid self assignment
    if(this == &m)
    {
        return *this;
    }
    else
    {
        this-> ~Matrix();
        rows = m.rows;
        cols = m.cols;
        allocateArrays();
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                data[i][j] = m.data[i][j];
        return *this;
    }
}

Matrix &Matrix::operator+=(const Matrix &m)
{
    // x+=y <=> x=x+y
    Matrix temp(*this); // copy constructor
    if(isMatrixSizeEqual(temp, m) == false)
        throw "Size of matrices are not equal";
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            data[i][j] += m.data[i][j];
    return *this;
}

/*
 * Return new Matrix with changed data
 */
Matrix Matrix::operator+(const Matrix &m)
{
    Matrix temp(*this); // use copy constructor
    return (temp+=m);
}

/*
 * Rerutn input Matrix with changed data
 */
Matrix &Matrix::operator-=(const Matrix &m)
{
    // x-=y <=> x=x-y
    Matrix temp(*this);
    if (isMatrixSizeEqual(temp, m) == false)
        throw "Size of matrices are not equal";
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            data[i][j] -= m.data[i][j];
    return *this;
}

/*
 * Return new Matrix
 */
Matrix Matrix::operator-(const Matrix &m)
{
    Matrix temp(*this);
    return (temp-=m);
}

/*
 * Return new transposed Matrix
 */
Matrix Matrix::transpose()
{
    Matrix temp(this->cols, this->rows);
    for(int i=0; i<temp.rows; i++)
        for(int j=0; j<temp.cols; j++)
            temp.data[i][j] = this->data[j][i];
    return temp;
}

/*
 * Print size of the Matrix on screen
 */
void Matrix::printSize()
{
    cout << rows << "x" << cols;
}

void Matrix::print()
{
    for(int i=0; i<rows; i++)
    {
        cout << "\t| ";
        for(int j=0; j<cols; j++)
        {
            cout << "" << data[i][j] << " ";
        }
        // print Size of Matrix on the end
        if(i==rows-1)
        {
            cout << "| ";
            printSize();
            cout << endl;
        }
        else
        {
            cout << "|" << endl;
        }
    }
}

/*
 * Return output stream (print) with Matrix
 */
ostream &operator<<(ostream &out, const Matrix &m)
{
    out << endl;
    for(int i=0; i<m.rows; i++)
    {
        out << "| ";
        for(int j=0; j<m.cols; j++)
            out << "" << m.data[i][j] << " ";
        out << "|" << endl;
    }
    return out;
}

/*
 * Return new Matrix
 */
Matrix operator*(const Matrix &m, const Matrix &n)
{
    if(m.cols != n.rows)
        throw "Column of matrix one not equal rows of matrix two";
    Matrix result(m.rows, n.cols);
    for (int i=0; i<result.rows; i++)
        for (int j=0; j<result.cols; j++)
            for (int k=0; k<m.cols; k++)
                result.data[i][j] += m.data[i][k] * n.data[k][j];
    return result;
}

/*
 * Return new Matrix; Number muptiply by Matrix
 */
Matrix operator*(const Matrix &m, double number)
{
    Matrix temp(m.rows, m.cols);
    for (int i=0; i<temp.rows; i++)
        for (int j=0; j<temp.cols; j++)
            temp.data[i][j] = number * m.data[i][j];
    return temp;
}

/*
 * Return new Matrix muptiply by number
 */
Matrix operator*(double number, const Matrix &m)
{
    return m * number;
}

/*
 * Return new Matrix raised to the Power
 */
Matrix operator^(const Matrix &m, long number)
{
    if(isMatrixSquare(m) == false)
        throw "Matrix is not sqaure";

    Matrix temp(m);
    if (number<-1)
    {
        throw "Can not to raise matrices to the power of negative numbers, excpet -1";
    }
    else if (number == -1)
    {
        /*
         * Odwracanie macierzy
         * z wykorzystaniem macierzy dopełnień algebraicznych
         */
        // Jeśli det(A) = 0 to macierz jest nieodwracalna
        if(determinant(temp) == 0)
            throw "Can not invert the matrix with determiant = 0";

        // jeśli det(A) jest różne od 0 to jest to macierz nieosobliwa (non-singular matrix)
        float detTemp = determinant(temp);
        Matrix D(temp.rows, temp.cols); // macierz dopełnień algebraicznych
        Matrix tempMatrix;

        for(int i=0; i<temp.rows; i++)
        {
            for(int j=0; j<temp.cols; j++)
            {
                tempMatrix = removeRow(temp,i+1);
                tempMatrix = removeColumn(tempMatrix,j+1);
                D.data[i][j] = determinant(tempMatrix);
                if( !isEvenNumber((i+1)+(j+1)) )
                {
                    D.data[i][j] *= -1;
                }
            }
        }
        return (1/detTemp)*(D.transpose());
    }
    else if (number == 0)
    {
        /*
         * Macierz jednostkowa
         */
        for (int i=0; i<temp.rows; i++)
            for (int j=0; j<temp.cols; j++)
                if(i == j)
                    temp.data[i][j] = 1;
                else
                    temp.data[i][j] = 0;
        return temp;
    }
    else
    {
        for (int q=1; q<=number; q++)
            for (int i=0; i<temp.rows; i++)
                for (int j=0; j<temp.cols; j++)
                    temp.data[i][j] = temp.data[i][j] * m.data[i][j];
        return temp;
    }
}

// TODO
/*
 * Return determinant of Matrix
 */
double determinant(const Matrix &m)
{
    if (isMatrixSquare(m) == false)
        throw "Matrix is not sqaure. Cannot calculate determianant of not square Matrix.";
    // For Matrix 1x1
    if (m.cols == 1 && m.rows == 1)
    {
        return m.data[0][0];
    }
    else if (m.cols == 2 && m.rows == 2)
    {
        // not loop 'cause this is the fastest method
        return ((m.data[0][0]*m.data[1][1]) - (m.data[0][1]*m.data[1][0]));
    }
    else if (m.cols == 3 && m.rows == 3)
    {
        // Sarrus Method
        // not loop 'cause this is much faster method
        return (m.data[0][0]*m.data[1][1]*m.data[2][2]
                + m.data[0][1]*m.data[1][2]*m.data[2][0]
                + m.data[0][2]*m.data[1][0]*m.data[2][1])
                -(m.data[0][2]*m.data[1][1]*m.data[2][0]
                + m.data[0][1]*m.data[1][0]*m.data[2][2]
                + m.data[0][0]*m.data[1][2]*m.data[2][1]);
    }
    else {
        /*
         * Rozwinięcie Laplace'a
         * http://www.math.edu.pl/rozwiniecie-laplacea
         */
        float result=0;
        for(int j=0; j<m.cols; j++)
        {
            // z założenia bierzemy zawsze 1 wiesz by było łatwiej analizować
            float temp = m.data[0][j];
            if( !isEvenNumber(1+(j+1)) )
                temp *= -1;
            Matrix tempMatrix = removeRow(m,1); // na stałe 1
            tempMatrix = removeColumn(tempMatrix,j+1);
            result += temp * determinant(tempMatrix);
        }
        return result;
    }
}

/*
 * Return number of rows
 */
int getNumberOfRows(const Matrix &m)
{
    return m.rows;
}

/*
 * Return number of columns
 */
int getNumberOfColumns(const Matrix &m)
{
    return m.cols;
}

/*
 * Return new Matrix with removed row
 * ex: for 3x3 long number are between 1-3
 */
Matrix removeRow(const Matrix &m, long numberOfRow)
{
    if(m.rows < 2)
        throw "Cannot remove row from Matrix that it has only one";
    Matrix temp(m.rows-1, m.cols);
    for (int i=0; i<m.rows; i++)
        for (int j=0; j<m.cols; j++)
        {
            if(i < numberOfRow-1)
            {
                temp.data[i][j] = m.data[i][j];
            }
            if(i > numberOfRow-1)
            {
                temp.data[i-1][j] = m.data[i][j];
            }
        }
    return temp;
}

/*
 * Return new Matrix with removed column
 * ex: for 3x3 long number are between 1-3
 */
Matrix removeColumn(const Matrix &m, long numberOfColumn)
{
    if(m.cols < 2)
        throw "Cannot remove column from Matrix that it has only one";
    Matrix temp(m.rows, m.cols-1);
    for (int j=0; j<m.cols; j++)
        for (int i=0; i<m.rows; i++)
        {
            if(j < numberOfColumn-1)
            {
                temp.data[i][j] = m.data[i][j];
            }
            if(j > numberOfColumn-1)
            {
                temp.data[i][j-1] = m.data[i][j];
            }
        }
    return temp;
}


// Protected -------------------------------------------------------------------
void Matrix::allocateArrays()
{
    if(rows<1)
        throw "Matrix rows must be equal or greater then 1";
    if(cols<1)
        throw "Matrix columns must be equal or greater then 1";
    data = new double *[rows];
    for(int i=0; i<rows; i++)
        data[i] = new double[cols];
}

void Matrix::removeWhiteCharacters(string &str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}

// Private ---------------------------------------------------------------------
