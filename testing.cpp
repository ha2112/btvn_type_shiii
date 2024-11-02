#include"bits/stdc++.h"

using namespace std;

int main(){
    vector<int> v;
    int a[] = {03212,32214,214213, 421412};
    int b[] = {100, 2193, 2131, 94032};
    for (auto x : a){
        v.push_back(x);
    }
    for (auto x : b){
        v.push_back(x);
    }
    sort(v.begin() , v.end());
    for (auto x : v){
        cout << x << " ";
    }

