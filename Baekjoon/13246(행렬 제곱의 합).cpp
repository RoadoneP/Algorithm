#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 10

using namespace std;

int n;
ll mat[MAX][MAX];
ll mat2[MAX][MAX];
ll result[MAX][MAX];
ll sum[MAX][MAX];

void Operator(ll a[][MAX], ll b[][MAX]) {

    int c[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = c[i][j];
        }
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n>>m;

    for (int i = 0; i < MAX; i++) {
        memset(sum[i], 0, sizeof(int) * MAX);
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            mat2[i][j] = mat[i][j];
        }
        result[i][i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int a = i;
        while (a) {
            cout << a << endl;
            if (a % 2 == 1) {
                Operator(result, mat2);
            }
            Operator(mat2, mat2);
            a /= 2;
        }
       
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                sum[j][k] = (sum[j][k]+result[j][k])%1000;
                result[j][k] = 0;
                mat2[j][k] = mat[j][k];
            }
            result[j][j] = 1;
        }
      
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sum[i][j] << ' ';
        }
        cout << endl;
    }
   
    

}