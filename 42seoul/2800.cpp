#include <iostream>
#include <stack>
#include <set>
#include <map>

using namespace std;

map<int, int> M;
string str;
set<string> S;

void dfs(string s, deque<int> dq, int idx) {
	for (; idx < str.size(); idx++) {
		if (str[idx] == '(' || str[idx] == ')')
			break;
		s.append(1, str[idx]);
	}
	if (idx >= str.size())
		S.insert(s);
	else {
		if (str[idx] == '(') {
			dfs(s + "(", dq, idx + 1);
			dq.push_back(idx);
			dfs(s, dq, idx + 1);
		} else {
			if (!dq.empty() && M[dq.back()] == idx) {
				dq.pop_back();
				dfs(s, dq, idx + 1);
			} else
				dfs(s + ")", dq, idx + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	stack<int> stk;
	int idx = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			stk.push(i);
		} else if (str[i] == ')') {
			M[stk.top()] = i;
			M[i] = stk.top();
			stk.pop();
		}
	}
	deque<int> dq;
	dfs("", dq, 0);
	for (auto s : S) {
		if (s == str) continue;
		cout << s << '\n';
	}
	return 0;
}