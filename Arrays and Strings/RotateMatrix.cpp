#include <iostream>
#include <map>
#include <vector>
using namespace std;

void rotate_usingcycles(vector<vector<int>> &mat) //90 degre anticlockwise
{
    int r = mat.size();
    int c = mat[0].size();

    //loop to run cycles
    for (int i = 0; i < r / 2; i++)
    {
        //loop to swap each element in a cycle
        for (int j = i; j < r - i - 1; j++)
        {
            //swap elements
            int temp = mat[i][j];
            mat[i][j] = mat[j][r - 1 - i];
            mat[j][r - 1 - i] = mat[r - 1 - i][r - 1 - j]; //for clockwise, start from the last swap.
            mat[r - 1 - i][r - 1 - j] = mat[r - 1 - j][i];
            mat[r - 1 - j][i] = temp;
        }
    }
}

void rotate_usingmathogic(vector<vector<int>> &mat)
{
    int N = mat.size();
    //first do the transpose
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    //now reverse the columns
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[i][N - j - 1];
            mat[i][N - j - 1] = temp;
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

    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    rotate_usingmathogic(mat);

    print_matrix(mat);

    return 0;
}