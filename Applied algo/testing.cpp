#include"bits/stdc++.h"

using namespace std;

const int N = 1e3+2;
int n, F[N][102], T, D, a[N], t[N], res;

void input(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= T; j++)
            F[i][j] = 0;
}

void proc(){
    for (int i = 1; i <= n; i++){
        for (int k = t[i]; k <= T; k++){
            for (int j = max(0, k - D); j < i; j++){
                F[i][k] = max(F[i][k], F[j][k - t[i]] + a[i]);
            }
            res = max(res, F[i][k]);
        }
    }
}

signed main(){
    input();
    proc();
    cout << res << endl;
}