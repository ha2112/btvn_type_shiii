#include <bits/stdc++.h>

using namespace std;

typedef struct pos{
    int x; 
    int y;
} pos;

vector<pos> visited;
queue<pos> q;
vector< vector<int> > a;


int BFS(pos start){
    
}

int main(){
    int n, m;
    pos start;
    cin >> n >> m >> start.x >> start.y;
    start.x--;
    start.y--;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
}