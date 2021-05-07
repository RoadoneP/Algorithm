#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 2010
#define INF 987654321

using namespace std;

int N, M, T, S, G, H, Dist_GH;
int Dist_S[MAX];
int Dist_G[MAX];
int Dist_H[MAX];

vector<pair<int, int>> V[MAX];
vector<int> Candidate;

void Initialize() {
    for (int i = 0; i < MAX; i++) {
        V[i].clear();
        Dist_S[i] = INF;
        Dist_G[i] = INF;
        Dist_H[i] = INF;
    }
    Candidate.clear();
}

void Input() {
    cin >> N >> M >> T;
    cin >> S >> G >> H;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        Candidate.push_back(a);
    }
}

void Dijkstra(int start, int Dist[MAX]) {
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, start));
    Dist[start] = 0;

    while (!PQ.empty()) {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < V[Cur].size(); i++) {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;

            if (Dist[Next] > Cost + nCost) {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
}
void Solution() {
    Dijkstra(S, Dist_S);
    Dijkstra(G, Dist_G); //1번째 G->H->A
    Dist_GH = Dist_G[H];
    Dijkstra(H, Dist_H); //2번째 H->G->A
    sort(Candidate.begin(), Candidate.end());
    for (int i = 0; i < Candidate.size(); i++) {
        int Dest = Candidate[i];
        if (Dist_S[Dest] == Dist_S[G] + Dist_GH + Dist_H[Dest])
            cout << Dest << " ";
        else if (Dist_S[Dest] == Dist_S[H] + Dist_GH + Dist_G[Dest])
            cout << Dest << " ";
    }
    cout << endl;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        Initialize();
        Input();
        Solution();
    }
    
}