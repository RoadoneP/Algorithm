#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 10001
using namespace std;

bool dp[MAX][MAX]; //구슬 n개로 숫자를 만들 수 있으면 1
int chu[MAX];
int n,m;
    

void solve(int cnt , int weight) {
    if (cnt > n)
        return;
    if (dp[cnt][weight])
        return;

    dp[cnt][weight] = true;

    solve(cnt + 1, weight + chu[cnt]);
    solve(cnt + 1, weight);
    solve(cnt + 1, abs(weight - chu[cnt]));
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, false, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> chu[i];
    }


    int marble;
    cin >> m;
    solve(0, 0);

    for (int i = 0; i < m; i++) {
        cin >> marble;
        if (dp[n][marble])
            cout << "Y ";
        else
            cout << "N ";

    }

}