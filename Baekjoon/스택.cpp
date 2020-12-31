#include<bits/stdc++.h>
#define endl '\n'
#define MAX 101
using namespace std;

bool Check(string str) {
	stack<int> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (s.empty())
				return false;
			else if (s.top() == '(')
				s.pop();
			else
				return false;
		}
		else if (str[i] == ']')
		{
			if (s.empty())
				return false;
			else if (s.top() == '[')
				s.pop();
			else
				return false;
		}
	}
	return s.empty();
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		string a;
		getline(cin, a);

		if (a[0] == '.')
			return 0;
		else {
			if (Check(a)) {
				cout << "yes" << endl;
			}
			else
				cout << "no" << endl;
		}
	}
}
