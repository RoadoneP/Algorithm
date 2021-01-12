#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 501
using namespace std;

int direct[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
int maze[MAX][MAX];
int solution[MAX][MAX];
int n, m;

int solve(int x, int y) {

    if (y == n - 1 && x == m - 1)
        return 1;
    if (solution[y][x] != -1)
        return solution[y][x];
    
    solution[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];

        if (0 <= nx && nx < m && 0 <= ny && ny <= n)
        {
            if (maze[ny][nx] < maze[y][x]) {
                solution[y][x] += solve(nx, ny);
            }
        }
    }
    return solution[y][x];

}




int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    memset(solution, -1, sizeof(solution));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    
    int ans=solve(0,0);
    cout << ans;
    
}