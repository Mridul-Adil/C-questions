#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void zeroMatusing_extraspace(vector<vector<int>> &mat)
{
    unordered_map<int, bool> rw;
    unordered_map<int, bool> cl;

    int R = mat.size();
    int C = mat[0].size();

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 0)
            {
                rw[i] = true;
                cl[j] = true;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (rw[i] == true || cl[j] == true)
            {
                mat[i][j] = 0;
            }
        }
    }
}

void zeroMatusing(vector<vector<int>> &mat)
{
    bool rw = false;
    bool cl = false;

    int R = mat.size();
    int C = mat[0].size();

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == 0 && mat[i][j] == 0 && rw == false) //store info of 1st col and 1st row int bool value.
            {
                rw = true;
            }

            if (j == 0 && mat[i][j] == 0 && cl == false)
            {
                cl = true;
            }

            if (mat[i][j] == 0) // for rest, use the 1st col and row in the matrix to store info
            {
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (mat[0][j] == 0 || mat[i][0] == 0)
            {

                mat[i][j] = 0;
            }
        }
    }

    if (rw == true)
    {
        for (int i = 0; i < C; i++)
        {
            mat[0][i] = 0;
        }
    }

    if (cl == true)
    {
        for (int i = 0; i < R; i++)
        {
            mat[i][0] = 0;
        }
    }
}

void print_matrix(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 3, 0},
                               {0, 6, 7, 8},
                               {9, 0, 11, 12},
                               {13, 14, 15, 16}};

    zeroMatusing(mat);

    print_matrix(mat);

    return 0;
}