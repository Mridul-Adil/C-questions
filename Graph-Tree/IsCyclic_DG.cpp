#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

enum Color
{
    WHITE,
    GREY,
    BLACK
};

class Graph
{
public:
    int N;
    map<int, list<int>> l;

    Graph(int N)
    {
        this->N = N;
    }

    void addedge(int x, int y)
    {
        l[x].push_back(y);
        }

    //Detecting a loop using colors     https://youtu.be/wQqFQeucFDc

    // bool isCyclic_DG_usingcolors_Util(int src, Color &clr)
    // {
    //     if (clr[src] == WHITE)
    //     {
    //         clr[src] = GREY;
    //         for (auto node : l[src])
    //         {
    //             if (isCyclic_DG_usingcolors_Util(node, clr))
    //             {
    //                 return true;
    //             }
    //         }
    //         clr[src] = BLACK;
    //     }
    //     else if (clr[src] == GREY)
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    // void isCyclic_DG_usingcolors(int src)
    // {
    //     Color clr[N];
    //     for (int i = 0; i < N; i++) //initializing all nodes to white
    //     {
    //         clr[i] = WHITE;
    //     }

    //     if (isCyclic_DG_usingcolors_Util(src, clr))
    //     {
    //         cout << "cyclic!!";
    //     }
    //     else
    //     {
    //         cout << "not cyclic";
    //     }
    // }

    //Detecting a loop using recursion stack              https://youtu.be/joqmqvHC_Bo

    bool isCyclic_directedgraph_Util(int src, vector<bool> &visited, vector<bool> &recstack)
    {
        if (visited[src] == false)
        {
            visited[src] = true;
            recstack[src] = true;

            for (auto node : l[src])
            {
                if (isCyclic_directedgraph_Util(node, visited, recstack))
                {
                    return true;
                }
            }
            recstack[src] = false;
        }
        else if (recstack[src] == true)
        {
            return true;
        }
        return false;
    }

    bool isCyclic_directedgraph(int src)
    {
        vector<bool> visited(N, false);
        vector<bool> recstack(N, false);

        if (isCyclic_directedgraph_Util(src, visited, recstack))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // Graph g(4);
    // g.addedge(0, 1);
    // g.addedge(0, 2);
    // g.addedge(1, 2);
    // g.addedge(2, 3);
    // g.addedge(3, 3);

    Graph p(4);
    p.addedge(0, 3);
    p.addedge(0, 2);
    p.addedge(2, 1);
    p.addedge(1, 3);
    //p.addedge(3, 3);

    // if (p.isCyclic_directedgraph(0))
    // {
    //     cout << "cyclic!!";
    // }
    // else
    // {
    //     cout << "not cyclic!";
    // }

    p.isCyclic_directedgraph(0);

    return 0;
}