#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{

public:
    vector<vector<pair<int, int>>> Graph;

    priority_queue<pair<int, int>> pq;
    vector<int> dist;
    Dijkstra(int n)
    {
        Graph.resize(n);
        dist.resize(n, INT_MAX);
    }
    void addEdge(int u, int v, int cost)
    {
        Graph[u].push_back({v, cost});
    }

    void traverse_graph(int source)
    {
        dist[source] = 0;

        pq.push({0, 0});

        while (!pq.empty())
        {

            pair<int, int> current_node;
            current_node = pq.top();
            pq.pop();
            cout << "node: " << current_node.second << " cost from source: " << current_node.first << endl;
            for (int i = 0; i < Graph[current_node.second].size(); i++)
            {

                pair<int, int> edge_node;
                edge_node = Graph[current_node.second][i];

                if (dist[edge_node.first] > -current_node.first + edge_node.second)
                {
                    dist[edge_node.first] = -current_node.first + edge_node.second;
                    pq.push({-dist[edge_node.first], edge_node.first});
                }
            }
        }
    }

    void printCost(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }

        cout << endl;
    }
};
int main()
{
    int n;
    cin >> n;

    Dijkstra dijkstra(n);

    dijkstra.addEdge(0, 1, 3);
    dijkstra.addEdge(1, 2, 1);
    dijkstra.addEdge(1, 5, 0);
     dijkstra.addEdge(5, 2, 0);
    dijkstra.traverse_graph(0);

    dijkstra.printCost(n);
}