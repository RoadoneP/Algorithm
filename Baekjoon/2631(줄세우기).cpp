#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define ll long long

using namespace std;
int n;
int dp[MAX];
int arr[MAX];
int maxv=0;

void solve() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (maxv < dp[i])
            maxv = dp[i];
    }
    cout << n-maxv;
}

int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    solve();
 


}