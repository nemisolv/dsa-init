#include <bits/stdc++.h>
using namespace std;

// this is a solution to the "Die Hard" problem in Codeforces

int check(const vector<int> v) {
    int n = v.size();
    map<int, int> mp = {
        {25,0},
        {50,0},
        {100,0}
    };
    for(int i = 0;i < n; i++) {
        if(v[i] == 100) {
            if(mp[50] >0 && mp[25] >0) {
                mp[50]--;
                mp[25]--;
            }else if(mp[25] >=3) {
                mp[25]-=3;
            }else {
                return 0;
            }
        }else if(v[i] == 50) {
            if(mp[25] > 0) {
                mp[25]--;
                mp[50]++;
            }else {
                return 0;
            }
        }else if(v[i] == 25) {
            mp[25]++;
        }else {
            return 0; // Invalid denomination   
        }
    }
    return 1;
}


int main()
{
#ifndef TEST_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int n; cin >> n;

vector<int> v(n);

for(int &x : v) cin >>x;
if(check(v)) cout << "YES";
else cout << "NO";


    return 0;
}