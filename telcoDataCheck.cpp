#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int totalCalls = 0;
    int incorrectPhone = 0;
    do {
        cin >> type;
        if (type == "#") continue;
        ++totalCalls;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if(!checkPhone(fnum) || checkPhone(tnum)) ++incorrectPhone;
        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime, etime);
    } while (type != "#");
    //Query implementation
    do {
        cin >> type;
        if(type == "#") continue;
        if(type == "?check_phone_number"){
            if (incorrectPhone == 0) cout << 1 << endl; else cout << 0 << endl;
        } else if (type == "?number_calls_from"){
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        } else if (type == "?number_total calls"){
            cout << totalCalls << endl;
        } else if (type == "?count_time_calls_from"){
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }
    }while (type != "#");
    return 0;
}