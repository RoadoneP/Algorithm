#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001
#define INF 987654321

using namespace std;

int m, n;

int memory[MAX];
int cost[MAX];
int dp[MAX];
int sum=0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }
    
    int i = 0;
    for (i = 0; i < sum, dp[i] < m; i++);
    cout << i << endl;

}