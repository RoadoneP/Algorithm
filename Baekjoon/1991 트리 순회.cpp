#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001
#define INF 987654321

using namespace std;
int n;

struct node {
    char left;
    char right;
};

struct node arr[27];

void preOrder(char root) {
    if (root == '.')
        return;
    cout << root;
    preOrder(arr[root].left);
    preOrder(arr[root].right);
}

void inOrder(char root) {
    if (root == '.')
        return;
    inOrder(arr[root].left);
    cout << root;
    inOrder(arr[root].right);
}

void postOrder(char root) {
    if (root == '.')
        return;
    postOrder(arr[root].left);
    postOrder(arr[root].right);
    cout << root;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    char a, b, c;

    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";

    return 0;
}