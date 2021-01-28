#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 10000

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll arr[101];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr[x] = arr[x] + 1;
    }

    ll maxm = 0;
    for (int i = 0; i <= n; i++) {
        maxm = max(maxm, arr[i]);
    }
    cout << maxm << endl;
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
