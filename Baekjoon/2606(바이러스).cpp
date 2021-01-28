#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 101

using namespace std;

bool Mat[MAX][MAX];
bool visited[MAX];
queue<int> q;
int m, n;
int cnt = 0;

void dfs(int v) {
    
    cnt++;
    visited[v] = true;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && Mat[v][i]) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    
    visited[v] = true;
    q.push(v);
    cnt++;
    
    while (!q.empty()) {
        
        v = q.front();
        q.pop();
        
        cout << v << " ";
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && Mat[v][i]) {
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    memset(Mat, false, sizeof(Mat));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int idx, num;
        cin >> idx >> num;

        Mat[idx][num] = true;
        Mat[num][idx] = true;
    }

    bfs(1);

    cout << cnt-1;


}