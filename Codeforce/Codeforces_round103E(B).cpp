#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 101

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k; // a[i]/sum+b <= k/100;
    int a[MAX];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sum = a[0];
    int result = 0;
    ll c = 0;

    for (int i = 1; i < n; i++) {
        int b = ((100 * a[i]) - (sum * k)) / k;
        
        if (b > 0) {
            result = b;
            sum += a[i] + result;
        }
        else{
            sum += a[i];
        }
        if(b>0)
            c += b;
    }
    cout << c<<endl;
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
