#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001

using namespace std;
int a[MAX];
queue<int> q;
int n, k;

int bfs(int start) {
    
    q.push(start);
    a[start] = 1;

    while (!q.empty()) {
        start = q.front();
        q.pop();
        if (start == k)
            return a[start]-1;
        if (start - 1 >= 0 && a[start - 1] == 0) {
            a[start - 1] = a[start] + 1;
            q.push(start - 1);
        }
        if (start + 1 <= 100000 && a[start + 1] == 0) {
            a[start + 1] = a[start] + 1;
            q.push(start + 1);
        }
        if (start*2 <= 100000 && a[start*2] == 0) {
            a[start*2] = a[start] + 1;
            q.push(start*2);
        }
     
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    memset(a, 0, sizeof(a));

    cout << bfs(n) << endl;
   
}