#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 10000

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int i = 1;
    int a = k;
    while (n > k) {
        k = k + a;
        i++;
    }
    if (k % n == 0) {
        cout << k / n << endl;
    }
    else {
        cout << (k / n) + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}