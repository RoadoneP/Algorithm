#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100

using namespace std;

int mat[MAX][MAX];
int visited[MAX][MAX];
int result[MAX][MAX];

int n, m, num;
queue<pair<int,int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
    
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    result[x][y] = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (mat[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                    result[nx][ny] += result[x][y] + 1;
                }
            }
        }
    }

}


int main() {

    ios_base::sync_with_stdio(0);
    //cin.tie(0);


    cin >> n >> m;

    memset(mat, 0, sizeof(mat));
    memset(visited, 0, sizeof(visited));
    memset(result, 0, sizeof(result));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &mat[i][j]);
        }
    }

    bfs(0, 0);

    cout << result[n - 1][m - 1];

    
}