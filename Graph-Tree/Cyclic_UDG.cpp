#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

template <typename T>
class Graph
{

    map<T, list<T>> l;

public:
    void
    addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto i : l[node])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    bool dfs_helper(T src, map<T, bool> &visited_dfs, T parent)
    {
        visited_dfs[src] = true;

        for (auto i : l[src])
        {
            if (!visited_dfs[i])
            {
                if (dfs_helper(i, visited_dfs, src))
                {
                    return true;
                }
            }
            else if (i != parent)
            {
                return true;
            }
        }
        return false;
    }

    void dfs(T src)
    {
        map<T, bool> visited_dfs;
        for (auto i : l)
        {
            T node = i.first;
            visited_dfs[node] = false;
        }

        if (dfs_helper(src, visited_dfs, src))
        {
            cout << "there is a cycle";
        }
        else
        {
            cout << "no cycle found";
        }
    }
};

int main()
{
    Graph<int> g;
    //g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    //g.bfs(0);
    //cout << endl;
    g.dfs(0);

    return 0;
}