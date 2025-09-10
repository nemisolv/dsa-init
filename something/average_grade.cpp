#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string s, char delim = ' ') {
    vector<string> result;
    int start = 0;
    for(int i = 0;i < s.size() ;i++) {
        if(s[i] == delim) {
            string temp = s.substr(start, i);
            result.push_back(temp);
            start = i;
        }
    }
    string last = s.substr(start);
    result.push_back(last);
    return result;
}

/*
INPUT: 
Lan 4 8 
Hanh 4 5
Lan 6 10 
Phong 4 10
Nam 4 9 
Phong 6 5 
Lan 2 4
Phuong 6 1
Nhung 2 7
Nhung 6 9 
Nhung 5 8 
Nhung 4 10 
Lan 3 1

OUT: 

Phuong: 1.00
Phong: 7.00
Nhung: 8.71
Nam: 9.00
Lan: 6.87
Hanh: 5.00

*/

int main()
{
#ifndef TEST_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    stringstream ss;
    string s;
    map<string, pair<int, int>> mp;
    while( getline(cin, s)) {
        vector<string> result = split(s);
        string name = result[0];
        int a = stoi(result[1]);
        int b = stoi(result[2]);
        if(mp.find(name) == mp.end()) {
            mp[name] = {a , a * b};
        }
        else {  
            mp[name].first += a;
            mp[name].second += (a*b);
        }
    }


    for(auto it  = mp.rbegin(); it != mp.rend(); it++) {
        string name = (*it).first;
        int credit = (*it).second.first;
        int grade = (*it).second.second;
        // cout << name << " : " << credit << " - " << grade<< endl;
        double avg = (double)grade / credit;
        // cout << name << endl;
        cout << name << ": "  << setprecision(2) << fixed << avg << endl;
    }


    return 0;
}