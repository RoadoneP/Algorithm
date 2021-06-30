#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100
#define INF 987654321

using namespace std;
int n;
int mat[MAX][MAX];
int visited[MAX] = {false};

void DFS(int a) {
    for (int i = 0; i < n; i++) {
        if (mat[a][i] == 1 && !visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }
    return;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        DFS(i);
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                mat[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}