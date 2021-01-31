#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 20001

using namespace std;

vector<int> mat[MAX];
int color[MAX]; // 방문여부 그리고 Red or black
int V, E;

bool dfs(int v, int RB) {

	//cout << "v: " << v << " RB: " << RB << endl;
	color[v] = RB;

	for (int i = 0; i < mat[v].size(); i++) {
		if (color[mat[v][i]] == 0) {
			if (dfs(mat[v][i], 3 - RB) == false)
				return false;
		}
		else if (color[v] == color[mat[v][i]]) {
			return false;
		}
	}
	return true;
}


void solve() {

	cin >> V >> E;
	bool F = true;

	for (int i = 1; i <= V; i++) {
		mat[i].clear();
		color[i] = 0;
	}

	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (!color[i]) {
			if (dfs(i, 1) == false) {
				F = false;
				break;
			}
		}
	}
	if (F) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
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