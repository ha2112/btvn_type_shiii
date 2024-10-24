#include"bits/stdc++.h"

using namespace std;


signed main(){
    string s = "111111111111111111111111111111111111";
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(l + 1 == r) break;
        int mid = (l + r) / 2;
        if(s[mid] == '0') l = mid;
        else r = mid;
    }
    cout << r << " " << s.size() - 1;
    
}