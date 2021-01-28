#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001

using namespace std;

int N, M;
int MAP[MAX][MAX];
bool visited[MAX][MAX][2]; //[x][y][벽을 부순 횟수]

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    //{x,y},{벽부순횟수,현재칸수}
    visited[0][0][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int b = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return cnt;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (MAP[nx][ny] == 1 && b == 0) { //벽은 있고 벽은 안부심
                    visited[nx][ny][1] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(b + 1, cnt + 1)));
                }
                else if (MAP[nx][ny] == 0 && visited[nx][ny][b] == false) {
                    //벽 없고 벽을 부셨거나 안부셨거나 하여간 안간곳일때
                    visited[nx][ny][b] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(b, cnt + 1)));
                }
            }
        }
    }
    return -1;
}


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &MAP[i][j]);
        }
    }
    int result = bfs();
    cout << result << endl;
}
