#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001

using namespace std;
int n, m;
int mat[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int,int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int,int>> onetozero;

void bfs(int x,int y) {
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (visited[nx][ny] == 0 && mat[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }
    }
}


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;
    int result = MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &mat[i][j]);
            visited[i][j] = 0;
            if (mat[i][j] == 1) {
                onetozero.push(make_pair(i, j));
            }
        }
    }

    bfs(0, 0);
    if(visited[n-1][m-1]!=0)
        result = visited[n - 1][m - 1];

    memset(visited, 0, sizeof(visited));

    while (!onetozero.empty()) {
        int cx = onetozero.front().first;
        int cy = onetozero.front().second;
        onetozero.pop();
        mat[cx][cy] = 0;
        bfs(0, 0);
        if (visited[n - 1][m - 1] == 0) {
            mat[cx][cy] = 1;
        }
        else {
            if (result > visited[n - 1][m - 1]) {
                result = visited[n - 1][m - 1];
            }
            mat[cx][cy] = 1;
        }
        memset(visited, 0, sizeof(visited));
    }
    
    if (result ==MAX)
        cout << "-1";
    else
        cout << result;
}