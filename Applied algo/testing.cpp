#include"bits/stdc++.h"

using namespace std;

const int N = 1e3 + 2, MOD = 1e9 + 7;
int n, k1, k2, F[N][2], res;

void input(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k1 >> k2;
}

void proc(){
    F[0][0] = F[0][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = k1; j <= k2; j++){
            if(i - j <  0) break;
            F[i][1] += F[i - j][0];
            F[i][1] %= MOD;
        }
        F[i][0] = F[i-1][1];
    }
    res = (F[n][0] + F[n][1]) % MOD;
    cout << res << endl;
}

signed main(){
    input();
    proc();
}