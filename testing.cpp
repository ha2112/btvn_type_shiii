#include<iostream>
#include<unordered_map>

using namespace std;

bool check(string a, string b){
    unordered_map<char, int> mp;
    int len = b.size();
    for (int i = 0; i < len; i++){
        mp[a[i]] += 1;
        // cout << a[i] << " " << mp[a[i]] << endl;
    }
    for (int i = 0; i < len; i++){
        mp[b[i]] -= 1;
        if(mp[b[i]] < 0) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> mp;
    int len = s1.size();
    for (char x : s1){
        mp[x] += 1;
    }
    for (int i = 0; i < s2.size(); i++){
        if(mp[s2[i]] != 0){
            if (check(&s2[i], s1)) return true;
        }
    }
    return false;
}

int main(){
    unordered_map<char, int> mp;
    string s1 = "dinitrophenylhydrazine";
    string s2 = "acetylphenylhydrazine";
    // cout << checkInclusion(s1, s2);
    cout << s1.size() <<endl;
    for (int i = 0; i < s1.size(); i++){
        cout << s1[i] << " ";
    }
    return 0;
}   //stupid me