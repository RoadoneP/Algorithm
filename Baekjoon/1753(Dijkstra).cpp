#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 20001
#define INF 987654321

using namespace std;

int V, E, start;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void Dijkstra() {

    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, start));
    Dist[start] = 0;

    while (!PQ.empty()) {
        int cost = -PQ.top().first;  //-를 붙이면 최소힙을 만들기 위해 힙안에 -로 되어있는 수를 다시 되돌린다.
        int cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < Vertex[cur].size(); i++) {
            int next = Vertex[cur][i].first;
            int nCost = Vertex[cur][i].second;

            if (Dist[next] > cost + nCost) {
                Dist[next] = cost + nCost;
                PQ.push(make_pair(-Dist[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF) cout << "INF" << endl;
        else cout << Dist[i] << endl;
    }

}




int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V >> E>> start;
  
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
       
        Vertex[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= V; i++)
        Dist[i] = INF;


    Dijkstra();


   
}