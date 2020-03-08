/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
*/

#include <iostream>

using namespace std;

void setZero(int matrix[][4])
{
    bool *zeroRows = new bool[4];
    bool *zeroCols = new bool[4];
    for (int i = 0; i < 4; i++)
    {
        zeroCols[i] = false;
        zeroRows[i] = false;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (matrix[i][j] == 0)
            {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (zeroRows[i] || zeroCols[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    delete(zeroRows);
    delete(zeroCols);
}

int main()
{
    int matrix[4][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 0, 10},
        {11, 12, 13, 14},
    };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    setZero(matrix);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
