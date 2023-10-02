#include <iostream>
using namespace std;

class Matrix
{
private:
    int **arr = new int *[3];

public:
    Matrix()
    {
        for (int i = 0; i < 3; i++)
        {
            arr[i] = new int[3];
        }
    }
    void acceptMatrix()
    {
        cout << "Matrix elements are = " << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "Enter the element for " << i << " & " << j << endl;
                int temp;
                cin >> temp;
                arr[i][j] = temp;
            }
        }
    }
    void printMatrix()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "The Matrix elements are " << i << " and " << j << " =" << arr[i][j] << endl;
            }
        }
    }
    friend void addMatrix(Matrix m1, Matrix m2);
    friend void subMatrix(Matrix m1, Matrix m2);
    friend void multiMatrix(Matrix m1, Matrix m2);
    friend void transMatrix(Matrix m1);
};

void addMatrix(Matrix m1, Matrix m2)
{
    int **arr2 = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new int[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr2[i][j] = m1.arr[i][j] + m2.arr[i][j];
        }
    }

    cout << "Addition of two matrix is: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr2[i][j] << "  ";
        cout << endl;
    }
}
void subMatrix(Matrix m1, Matrix m2)
{
    int **arr2 = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new int[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr2[i][j] = m1.arr[i][j] - m2.arr[i][j];
        }
    }
    cout << "Subtraction of two matrix is: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr2[i][j] << "  ";
        cout << endl;
    }
}
void multiMatrix(Matrix m1, Matrix m2)
{

    int **arr2 = new int *[3];

    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new int[3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr2[i][j] = 0;

            for (int k = 0; k < 3; k++)
                arr2[i][j] += m1.arr[i][k] * m2.arr[k][j];
        }
    }

    // Printing the result
    cout << endl
         << "Multiplication of two matrix is: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr2[i][j] << "  ";
        cout << endl;
    }
}

// Transpose of a matrix
void transMatrix(Matrix m1)
{

    int **arr2 = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new int[3];
    }

    // Calculating the Transpose
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            arr2[i][j] = m1.arr[j][i];

    // Printing the result
    cout << endl
         << "Transpose of the matrix is: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr2[i][j] << "  ";
        cout << endl;
    }
}

int main()
{
    Matrix m1;
    cout << "-----------------First Matrix------------------";
    m1.acceptMatrix();
    // m1.printMatrix();

    Matrix m2;
    cout << "-----------------Second Matrix------------------";
    m2.acceptMatrix();
    // m2.printMatrix();

    addMatrix(m1, m2);
    subMatrix(m1, m2);
    multiMatrix(m1, m2);
    transMatrix(m1);
    return 0;
}