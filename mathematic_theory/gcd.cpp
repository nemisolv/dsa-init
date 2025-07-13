#include<iostream>

using namespace std;

int gcd(int a, int b) {
    // way 1
    // if(b ==0) return a;
    // return gcd(b, a%b);

    while(b!=0) {
        int temp = a %b;
         a= b;
         b = temp;
    }
    return a;




}


int main() {
    int a, b;
    cin >> a>>b;
    cout << gcd(a,b);
}