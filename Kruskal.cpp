#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent;
vector<int> rank;

void makeSet(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int findSet(int x) {
    if (x != parent[x])
        parent[x] = findSet(parent[x]);
    return parent[x];
}

void link(int x, int y) {
    if (rank[x] > rank[y])
        parent[y] = x;
    else {
        parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
}

vector<Edge> Kruskal(int V, vector<Edge>& edges) {
    vector<Edge> result;
    parent.resize(V);
    rank.resize(V);

    for (int x = 0; x < V; x++)
        makeSet(x);

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (auto edge : edges) {
        int ru = findSet(edge.u);
        int rv = findSet(edge.v);

        if (ru != rv) {
            link(ru, rv);
            result.push_back(edge);

            if (result.size() == V - 1)
                break;
        }
    }

    if (result.size() != V - 1) {
        cout << "ERROR: The graph is not connected." << endl;
        return {};
    }

    return result;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    vector<Edge> mst = Kruskal(V, edges);

    if (!mst.empty()) {
        cout << "Minimum Spanning Tree Edges:" << endl;
        for (auto edge : mst) {
            cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
        }
    }

    return 0;
}
