#include <bits/stdc++.h>

using namespace std;

// way 1
// int map2Int(char c) {
//     switch (c)
//     {
//     case 'I':
//         return 1;
//     case 'V':
//         return 5;
//     case 'X':
//         return 10;
//     case 'L':
//         return 50;
//     case 'C':
//         return 100;
//     case 'D':
//         return 500;
//     case 'M':
//         return 1000;
//     default:
//         return 0;
//     }
// }

// int romanToInt(string s)
// {
//     int res = 0;
//     for(int i = s.size()-1;i >=0;i--) {
//         int temp = map2Int(s[i]);
//         if(i>0) {

//             if(s[i-1]=='I' && (s[i] == 'V' || s[i] == 'X')) {
//                 temp-=1; i--;
//             }else if(s[i-1]=='X' && (s[i] == 'L' || s[i] == 'C')) {
//                 temp-=10; i--;
//             }else if(s[i-1]=='C' && (s[i] == 'D' || s[i] == 'M')) {
//                 temp-=100; i--;
//             }
//         }
//         res+=temp;
//     }

//     return res;
// }

// way 2

int romanToInt(string s)
{
    unordered_map<char, int> mp{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int ans = mp[s[s.size() - 1]];
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            ans -= mp[s[i]];
        }
        else
        {
            ans += mp[s[i]];
        }
    }
    return ans;
}

int main()
{
    string x;
    cin >> x;
    cout << romanToInt(x);
    return 0;
}