#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1000
#define INF 987654321

using namespace std;

int n, k, d, w;
int Result_Time[MAX];
int Time[MAX];
int Entry[MAX];
vector<int> Build[MAX];

void Init() {
    memset(Time, 0, sizeof(Time));
    memset(Result_Time, 0, sizeof(Result_Time));
    memset(Entry, 0, sizeof(Entry));
    for (int i = 0; i < MAX; i++) {
        Build[i].clear();
    }
}

void Solution() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (Entry[i] == 0) {
            q.push(i);
            Result_Time[i] = Time[i];
        }
    } // 연결 되어있지 않은 노드는 결과값이 자기 자신이 된다.

    while (!q.empty()) {
        int Cur = q.front();
        q.pop();

        for (int i = 0; i < Build[Cur].size(); i++) {
            int Next = Build[Cur][i];
            Result_Time[Next] = max(Result_Time[Next], Result_Time[Cur] + Time[Next]);
            Entry[Next]--;

            if (Entry[Next] == 0)
                q.push(Next);
        }
    }
    cout << Result_Time[w] << endl;
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        Init();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> Time[i];
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            Build[a].push_back(b);
            Entry[b]++;
        }
        cin >> w;
        Solution();
    }
    
}