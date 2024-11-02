#include"bits/stdc++.h"

using namespace std;


class Sol{
public:
    int static count(int a, int b, vector<int> lista, vector<int> listb){
        int ans = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < a; i++){
            count[lista[i]]++;
        }
        for (int i = 0; i < b; i++){
            if (count.find(listb[i]) != count.end() && count[listb[i]] > 0){
                count[listb[i]]--;
                ans++;
            }
        }
        return ans;
    }
};


signed main(){
    vector<int> lista, listb;
    int arr[] = {2,1,4,3};
    int brr[] = {1,5,4};
    for (auto x : arr){
        lista.push_back(x);
    }
    for (auto x : brr){
        listb.push_back(x);
    }
    Sol solu;
    cout << solu.count(4, 3, lista, listb);
}

//there's sth wrong with my c++