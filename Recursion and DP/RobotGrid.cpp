#include <iostream>
#include <map>
#include <vector>
using namespace std;

int noOfways(vector<vector<int>> grid)
{
    //vector<vector<int>> paths;

    int R = grid.size();
    int C = grid[0].size();

    vector<vector<int>> paths(R, vector<int>(C, 0)); //*in case of 2d vector, first initialize as it will be used like an array arr[x][y]

    if (grid[0][0] == 1)
    {
        paths[0][0] = 1;
    }
    else
    {
        return -1;
    }

    //initialize the first row
    for (int i = 1; i < R; i++)
    {

        if (grid[i][0] == 1)
        {
            paths[i][0] = paths[i - 1][0];
        }
    }

    //initialize the first column
    for (int i = 1; i < C; i++)
    {

        if (grid[0][i] == 1)
        {
            paths[0][i] = paths[0][i - 1];
        }
    }

    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (grid[i][j] == 1)
            {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
            else //if there is an obstacle
            {
                paths[i][j] == 0;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {

            cout << paths[i][j] << " ";
        }
        cout << endl;
    }

    return paths[2][2];
}

int main()
{
    //here 0 is the obstacle and 1 is the free way
    vector<vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    cout << noOfways(grid);
    return 0;
}