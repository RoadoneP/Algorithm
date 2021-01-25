#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001

using namespace std;

bool Mat[MAX][MAX];
bool visited[MAX];
int n, m, v;
queue<int> q;

void dfs(int v) {
    cout << v << " ";
    visited[v] = true;
    for (int i = 1; i <= n; i++) {
        if (Mat[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    visited[v] = 1;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        cout << v << " ";
        for (int i = 1; i <= n; i++) {
            if (Mat[v][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> v;

    for (int i = 0; i < MAX; i++)
        memset(Mat[i], false, sizeof(bool) * MAX);
    memset(visited, false, sizeof(bool) * MAX);

    for (int i = 0; i < m; i++) {
        int idx, num;
        cin >> idx >> num;

        Mat[idx][num] = true;
        Mat[num][idx] = true;
    }

    dfs(v);
    cout << endl;

    memset(visited, false, sizeof(bool) * MAX);
    bfs(v);
    cout << endl;
    
   

}