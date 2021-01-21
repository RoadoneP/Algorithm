#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 51

using namespace std;

int tmp[MAX][MAX];
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };
int cnt = 0;
int n, m;
int y, x, d;

int dir(int d) {
    if (d == 0) return 3;
    if (d == 1) return 0;
    if (d == 2) return 1;
    else return 2;
}
int back_dir(int d) {
    if (d == 0) return 2;
    if (d == 1) return 3;
    if (d == 2) return 0;
    else return 1;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    cin >> x >> y >> d;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp[i][j];
        }
    }

    while (1) {

        if (tmp[x][y] == 0) {
            tmp[x][y] = 2;
            cnt++;
        }

        int next = 0;

        for (int i = 0; i < 4; i++) {

            d = dir(d);

            int dx = x + dir_x[d];
            int dy = y + dir_y[d];
            //0 이있으면

            if (tmp[dx][dy] == 0) {
                x = dx;
                y = dy;
                next = 1;
                break;
            }
        }
        if (next == 1)
            continue;

        int back_d = back_dir(d);
        x = x + dir_x[back_d];
        y = y + dir_y[back_d];

        if (tmp[x][y] == 1)
            break;

    }
    cout << cnt;

    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tmp[i][j]<< ' ';
        }
        cout << endl;
    }

}