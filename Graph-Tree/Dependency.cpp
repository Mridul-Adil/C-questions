#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class Graph
{

    map<T, list<T>> l;

public:
    void addEdge(T a, T b)
    {

        l[a].push_back(b);
    }

    void toposort_BFS()
    {
        queue<T> q;
        map<T, int> degree;
        vector<T> toporder;

        //initialize the degree with zeroes

        //traverse the graph. fill the degree
        for (auto i : l)
        {
            if (degree[i.first] < 1)
            {
                degree[i.first] = 0;
            }

            for (auto j : i.second)
            {
                degree[j]++;
            }
        }

        //add those elements to the queue who has the degree one(no dependency)
        for (auto i : degree)
        {

            if (i.second == 0)
            {
                q.push(i.first);
            }
        }

        //now go to the neighbours of elements in the queue. decrease each dregree by one. If any neighbour has 1 degree, add to q
        while (!q.empty())
        {

            T node = q.front();
            q.pop();
            toporder.push_back(node);

            for (auto nbr : l[node])
            {
                if (--degree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        //print the toporder
        for (auto i : toporder)
        {
            cout << i << "->";
        }
    }

    void toposort_DFSUtil(T node, map<T, bool> &visited, stack<T> &toporder)
    {
        visited[node] = true;

        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                toposort_DFSUtil(nbr, visited, toporder);
            }
        }

        toporder.push(node);
    }

    void toposort_DFS()
    {

        map<T, bool> visited;
        stack<T> toporder;

        //populate the whole visited map with false(not visited)
        for (auto i : l)
        {
            visited[i.first] = false;
            for (auto j : l[i.first])
            {
                visited[j] = false;
            }
        }

        for (auto i : l)
        {
            if (!visited[i.first])
            {
                toposort_DFSUtil(i.first, visited, toporder);
            }
        }

        //print elements in the stack
        while (!toporder.empty())
        {
            cout << toporder.top() << "->";
            toporder.pop();
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(5, 2); //5 is dependent on 2
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.toposort_DFS();
    cout << endl;
    g.toposort_BFS();
    return 0;
}