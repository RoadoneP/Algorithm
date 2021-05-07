#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100000001
#define ll long long

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    ll ans = INT_MAX;
    for (int i = b; i <= b + 100; i++) {
        if (i == 1)
            continue;
        ll add = 0;
        int k = a;
        while (k) {
            k /= i;
            add++;
        }
        ans = min(ans, i - b + add);
    }
    cout << ans << endl;
}



int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

}