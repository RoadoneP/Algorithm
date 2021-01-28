#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 10000

using namespace std;

bool findDigit(ll num, int d)
{
    ll b = num;
    while (b > 0) {
        if (b % 10 == d) {
            return 1;
        }
        b /= 10;
    }
    return 0;
}



void solve()
{
    int q, d;
    cin >> q >> d;
    while (q--) {
        ll a;
        cin >> a;
        bool ans = 0;
        while (a > 0) {
            if (findDigit(a, d)) {
                ans = 1;
                break;
            }
            a -= d;
        }
        cout << (ans ? "YES\n" : "NO\n");
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
