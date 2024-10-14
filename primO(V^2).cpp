#include <bits/stdc++.h>
#define NMAX 1000

using namespace std;

int v, V, near[NMAX], d[NMAX], c[NMAX][NMAX];
bool mst[NMAX] = {false};

int findMin()
{
    int minD = INT_MAX;
    int index;
    for(v = 1; v < V; v++)
    {
        if(!mst[v] && d[v] < minD) 
        {
            minD = d[v];
            index = v;
        }
    }
    return index;
}

void prim()
{
    mst[0] = true;
    d[0] = 0;
    near[0] = 0;
    for(int k = 1; k < v; k++)
    {
        d[v] = c[0][v];
        near[v] = 0;
    }
    for(int k = 1; k < v; k++)
    {
        int v = findMin();
        mst[v] = true;
        for (int i = 1; i < V; i++) 
        if(!mst[i] && d[i] > c[v][i])
        {
            d[i] = c[v][i];
            near[i] = v;
        }   
    }
    for(int i = 1; i < V; i++) 
    {
        cout << near[i] << i << "\t" << c[i][near[i]] << endl;
    }
}

int main()
{
    cin >> V;
    for(int i = 0; i < V; i++) 
    {
        for(int j = 0; j < V; j++) 
        {
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < V; i++) 
    {
        d[i] = INT_MAX;
    }
    prim();
}