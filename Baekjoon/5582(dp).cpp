#include<bits/stdc++.h>
#define endl "\n"
#define MAX 4001
#define ll long long

using namespace std;
string str1;
string str2;
int dp[MAX][MAX];
int maxv=0;

void solve() {

    int len1 = str1.size();
    int len2 = str2.size();

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {

                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                if (maxv < dp[i][j])
                    maxv = dp[i][j];
            }
        }

    }
    cout << maxv<<endl;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            cout << dp[i][j]<< " ";
        }
        cout << endl;
    }
}

int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str1;
    cin >> str2;

    solve();

    
}