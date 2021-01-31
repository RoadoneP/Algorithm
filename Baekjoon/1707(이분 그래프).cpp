#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 20001

using namespace std;

bool mat[MAX][MAX];
int visited[MAX]; // 방문여부 그리고 Red or black
int V, E;

void dfs(int v,int RB) {

	//cout << "v: " << v << " RB: " << RB << endl;
	
	if (RB == 0)
		visited[v] = 1;
	else
		visited[v] = 2;

		for (int i = 1; i <= V; i++) {
		if (mat[v][i] && !visited[i] && RB==0) {
			dfs(i, 1);
		}
		else if (mat[v][i] && !visited[i] && RB == 1) {
			dfs(i, 0);
		}
	}
}

void solve(){
	
	cin >> V >> E;
	bool F = false;

	memset(mat, 0, sizeof(mat));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < E; i++) {
		int a,b;
		cin >> a>>b;
		mat[a][b] = true;
		mat[b][a] = true;
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (mat[i][j] == 1 && !visited[i]) {
				dfs(i, 0);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (mat[i][j] == 1) {
				if (abs(visited[i] - visited[j]) == 1)
					continue;
				else
				{
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	cout << "YES" << endl;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	

}