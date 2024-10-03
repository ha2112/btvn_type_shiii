#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iomanip>

using namespace std;

struct Call {
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

bool is_valid_phone_number(const string& number) {
    if (number.length() != 10) return false;
    for (char c : number) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

int time_to_seconds(const string& time) {
    int h, m, s;
    sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

int calculate_duration(const string& start, const string& end) {
    return time_to_seconds(end) - time_to_seconds(start);
}

int main() {
    vector<Call> calls;
    unordered_map<string, int> call_count;
    unordered_map<string, int> call_duration;
    string line;

    // Read call data
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string prefix;
        Call call;
        iss >> prefix >> call.from_number >> call.to_number >> call.date >> call.from_time >> call.end_time;
        calls.push_back(call);
        call_count[call.from_number]++;
        call_duration[call.from_number] += calculate_duration(call.from_time, call.end_time);
    }

    // Process queries
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string query_type;
        iss >> query_type;

        if (query_type == "?check_phone_number") {
            bool all_valid = true;
            for (const Call& call : calls) {
                if (!is_valid_phone_number(call.from_number) || !is_valid_phone_number(call.to_number)) {
                    all_valid = false;
                    break;
                }
            }
            cout << endl << (all_valid ? "1" : "0") << endl;
        }
        else if (query_type == "?number_calls_from") {
            string phone_number;
            iss >> phone_number;
            cout << endl << call_count[phone_number] << endl;
        }
        else if (query_type == "?number_total_calls") {
            cout << endl << calls.size() << endl;
        }
        else if (query_type == "?count_time_calls_from") {
            string phone_number;
            iss >> phone_number;
            cout << endl << call_duration[phone_number] << endl;
        }
    }

    return 0;
}