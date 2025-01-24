#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int C;
bool T[10000001];
set<int> answer;

void dfs(int idx, string &s, string &t, vector<bool> &v) {
	if (idx >= s.size()) {
		if (t.empty()) return;
		int p = stoi(t);
		if (!T[p]) answer.insert(p);
		return;
	}
	dfs(idx + 1, s, t, v);
	for (int i = 0; i < s.size(); i++) {
		if (v[i]) continue;
		t.push_back(s[i]);
		v[i] = true;
		dfs(idx + 1, s, t, v);
		v[i] = false;
		t.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> C;
	T[0] = true; T[1] = true;
	for (int i = 2; i <= 10000000; i++) {
		if (T[i]) continue;
		for (int j = i + i; j <= 10000000; j += i)
			T[j] = true;
	}
	while (C--) {
		string S;
		cin >> S;
		answer.clear();
		string t;
		vector<bool> v(S.size());
		dfs(0, S, t, v);
		cout << answer.size() << '\n';
	}

	return 0;
}