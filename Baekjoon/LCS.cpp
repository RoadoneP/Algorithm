#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001

using namespace std;

string str1, str2;

int lcs[MAX][MAX];

void solve() {
    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {

            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
                continue;
            }
            if (str1[i] == str2[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    stack<int> st;

    int i = str1.size() - 1;
    int j = str2.size() - 1;
    while (lcs[i][j]) {
        if (lcs[i][j] == lcs[i][j - 1])
            j--;
        else if (lcs[i][j] == lcs[i - 1][j])
            i--;
        else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])
        {
            st.push(i);
            i--;
            j--;
        }
    }

    cout << lcs[str1.size() - 1][str2.size() - 1] << endl;

    while (!st.empty())
    {
        cout << str1[st.top()];
        st.pop();
    }
    return;
}

int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(lcs, 0, sizeof(lcs));

    cin >> str1;
    cin >> str2;
    
    str1 = '0' + str1;
    str2 = '0' + str2;

    solve();
}