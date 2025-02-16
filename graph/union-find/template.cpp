#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> parent, rank;

    UnionFind(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);

        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int find(int value)
    {
        if (parent[value] == value)
            return value;

        parent[value] = find(parent[value]);

        return parent[value];
    }

    void make_union(int valueOne, int valueTwo)
    {
        int rootOne = find(valueOne);
        int rootTwo = find(valueTwo);

        if (rank[rootOne] >= rank[rootTwo])
        {
            parent[rootTwo] = rootOne;
            rank[rootOne]++;
        }

        else
        {
            parent[rootOne] = rootTwo;
            rank[rootTwo]++;
        }
    }
};
int main()
{
    int n;
    cin >> n;

    UnionFind uf(n);

    cout << uf.find(1) << " " << uf.find(2) << endl;

    uf.make_union(1, 2);
    uf.make_union(2, 3);

    cout << uf.find(2) << " " << uf.find(3) << endl;
    uf.make_union(4, 5);
    uf.make_union(5, 6);
    cout << uf.find(5) << " " << uf.find(6) << endl;
    uf.make_union(3, 4);

    cout << uf.find(2) << " " << uf.find(3) << " " << uf.find(4) << " " << uf.find(5) << " " << uf.find(6) << endl;
}