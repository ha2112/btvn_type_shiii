#include<bits/stdc++.h>

using namespace std;

bool legit(string s){
    string a;
    if (s[0] != '-'){
        a = "2147483647";
    } else {
        a = "-2147483648";
    }
    if (s.size() < a.size()) return true;
    if (s.size() > a.size()) return false;
    for(int i = 0; i < s.size(); i++){
        if (a[i] > s[i]) return true;
        else if (a[i] < s[i]) return false;
    }
    return true;
}


int reverse(int x) {
    string s = to_string(x);
    cout << s << endl;
    int start;
    if (s[0] == '-'){
            start = 1;
    } else {
        start = 0;
    } 
    int n = s.size();
    for (int i = start; i <= n/2; i++){
        swap(s[i], s[n-i-(1-start)]);
        cout << i << endl;
    }
    int ans = 0;
    cout << start << endl << s << endl;
    if(legit(s)){
        for (int i = start; i < n; i++){
            ans *= 10;
            ans += s[i] - '0';
        }
    }
    if (start == 1){
        return -ans;
    } else {
        return ans;
    }
}

signed main(){
    // char a = '0' - 47;
    // cout << endl << a << endl;
    cout << endl << reverse(-23) << endl;
}