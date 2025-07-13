#include<iostream>

using namespace std;


int is_palindrome(int x) {
    if(x < 0 ||(x %10 ==0 && x!=0)) return 0;

    int reverse = 0;
    while(reverse < x) {
        reverse = reverse*10 + x%10;
        x/=10;
    }
    return reverse ==x || x== reverse/10;
}


int main() {
    int x;
    cin >>x;

    cout << is_palindrome(x);

    return 0;
}