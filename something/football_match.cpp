#include <bits/stdc++.h>
using namespace std;


int split(const string s, char delimeter = '-') {
    int index = 0;
    for(int i = 0;i < s.size(); ++i) {
        if(s[i] == delimeter) {
            index = i;
            break;
        }
    }
    return index;
}



int main()
{
#ifndef TEST_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; cin >> n;
    map<string, vector<string>> mp;
    cin.ignore(); // To ignore the newline character after reading n
    for(int i = 1;i <= n; i++) {
        string s; getline(cin, s);
        string first = s.substr(0, split(s) -1);
        string second = s.substr(split(s) + 2);
        mp[first].push_back(second);
        mp[second].push_back(first);
    }

    for( auto it : mp) {
        cout << it.first << ": ";
        sort(it.second.begin(), it.second.end());
        for(int i = 0;i <  it.second.size();i++) {
            cout << it.second[i];
            if(i != it.second.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}