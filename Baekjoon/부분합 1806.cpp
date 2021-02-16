#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001
#define INF 987654321

using namespace std;
int n,m;
int arr[MAX];
int L, R, sum, ans;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sum = arr[0];
    L = 0;
    R = 0;
    ans = INF;
   
    while (L < n && R < n) {
        if (sum < m) {
            sum += arr[++R];
        }
        else if (sum == m) {
            ans = min(ans, R - L + 1);
            sum += arr[++R];
        }
        else if (sum > m) {
            ans = min(ans, R - L + 1);
            sum -= arr[L++];

            if (L > R) {
                R = L;
                sum = arr[L];
            }
        }
    }
    if (ans = INF)
        cout << 0 << endl;
    else
        cout << ans << endl;
}