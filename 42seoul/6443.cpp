#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
string A[21];

void dfs(int idx, int seq, string &s, vector<bool> &v, set<string> &t) {
	if (idx >= A[seq].size()) {
		cout << s << '\n';
		return;
	}
	t.insert(s);
	for (int i = 0; i < A[seq].size(); i++) {
		if (v[i]) continue;
		v[i] = true;
		s.push_back(A[seq][i]);
		if (t.find(s) == t.end())
			dfs(idx + 1, seq, s, v, t);
		v[i] = false;
		s.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sort(A[i].begin(), A[i].end());
		string s;
		vector<bool> v(A[i].length());
		set<string> t;
		dfs(0, i, s, v, t);
	}
	return 0;
}