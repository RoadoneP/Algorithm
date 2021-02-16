#include<bits/stdc++.h>
#define endl "\n"
#define MAX 2002
#define ll long long

using namespace std;

int visited[MAX][MAX];
int n;
queue<pair<pair<int,int>,int>> q;

int bfs(int window,int clip) {
       
    visited[window][clip] = 1;
    q.push(make_pair(make_pair(window, clip), 0));

    while (!q.empty()) {
        int dis = q.front().first.first;
        int clip = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if (dis == n)
            return time;

        if (dis > 0 && dis < MAX) {

            //클립보드에 저장
            if (visited[dis][dis] == 0) {
                visited[dis][dis] = 1;
                q.push(make_pair(make_pair(dis, dis), time + 1));
            }
            //이모티콘 삭제
            if (visited[dis - 1][clip] == 0) {
                visited[dis][clip] = 1;
                q.push(make_pair(make_pair(dis-1, clip), time + 1));
            }
        }
        //붙여넣기
        if (clip > 0 && clip + dis < MAX) {
            if (visited[dis + clip][clip] == 0) {
                visited[dis + clip][clip] = 1;
                q.push(make_pair(make_pair(dis+clip, clip), time + 1));
            }
        }
    }
    
}

int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    memset(visited, 0, sizeof(visited));

    cout<<bfs(1,0);

}