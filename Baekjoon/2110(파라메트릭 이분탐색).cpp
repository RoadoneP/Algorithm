#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 200001

using namespace std;
ll n;
ll c;
ll a[MAX];
ll b = 1;
ll mid = 0;

void solve(ll left, ll right,int cnt) {
    mid = (left + right) / 2;

    if (right < left)
        return;
    else
    {
        int inv = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] - inv >= mid)
            {
                b++;
                inv = a[i];
            }
        }
        if (b >= cnt) {
            b = 1;
            solve(mid + 1, right, cnt);
        }
        else {
            b = 1;
            solve(left, mid - 1, cnt);
        }
    }
}



int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    solve(0, a[n - 1],c);

    cout << mid;

}
