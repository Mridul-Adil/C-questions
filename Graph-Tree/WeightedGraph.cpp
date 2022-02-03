#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;

class Graph
{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string a, string b, bool bidir, int wt)
    {
        l[a].push_back(make_pair(b, wt));
        if (bidir)
        {
            l[b].push_back(make_pair(a, wt));
        }
    }
    void printWeightedGraph()
    {
        for (auto i : l)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.printWeightedGraph();

    return 0;
}