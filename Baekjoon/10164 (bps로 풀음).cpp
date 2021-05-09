#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 16
#define INF 987654321

using namespace std;
   
int n, m, k;
int a[MAX][MAX];
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
int c, r;

int bps(int x, int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    a[x][y] = 0;
    bool temp = true;
    if (x == 0 && y == 0) {
        temp = false;
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                a[nx][ny] += 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if (temp == false) {
        return a[r][c];
    }
    else
        return a[n - 1][m - 1];
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;


    if (k != 0) {
        r = k / m;
        if (k % m == 0)
            c = m - 1;
        else
            c = k % m - 1;
    }
    else {
        c = m-1;
        r = n-1;
    }
    
    int first = bps(0, 0);
    int second = 1;
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */
    if (k != 0) {
        memset(a, 0, sizeof(a));
        second = bps(r, c);
    }
    
    cout << first*second;
}