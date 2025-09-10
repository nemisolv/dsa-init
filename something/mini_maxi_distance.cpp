#include <bits/stdc++.h>
using namespace std;



int main()
{
#ifndef TEST_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

int n; cin >> n;

vector<int> a(n);

for(int &x : a) cin >>x;
cout << a[1] - a[0] << " " << a[n - 1] - a[0] << endl;
for(int i = 1; i < n - 1; i++
) {
    cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << " ";
    cout << max(a[i] - a[0], a[n - 1] - a[i]) << endl;
}
cout << a[n - 1] - a[n - 2] << " " << a[n - 1] - a[0] << endl;



    return 0;
}