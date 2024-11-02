#include<bits/stdc++.h>

using namespace std;

signed main(){
    string s = "A man, a plan, a canal: Panama";
    int dist = 'A' - 'a';
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n; i++){
        if('a' <= s[i] && 'z' >= s[i]) ans+=s[i];
        else if('A' <= s[i] && 'Z' >= s[i]) ans += (s[i] - dist);
        else continue;
    }
    cout << ans;
}

// testing purpose only