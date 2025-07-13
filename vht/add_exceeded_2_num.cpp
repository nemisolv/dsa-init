#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// add two numbers represented as digit vectors ( reversed order )

string add(string &s1, string &s2) {
    if(s1.empty()) return s2;
    if(s2.empty()) return s1;
    int carry = 0;
    string result;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0)  {
        int digit1 = (i >= 0) ? s1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? s2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum%= 10;
        result.push_back('0' + sum);

    }

    while( result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
        
}

int main () {
    int a = 2000000123;
    int b = 2000000456;
    string s1 = to_string(a);
    string s2 = to_string(b);
    string result = add(s1, s2);
    cout << "The sum of " << a << " and " << b << " is: " << result << endl;
    return 0;

}