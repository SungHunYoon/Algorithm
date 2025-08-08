#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;
using sii = tuple<string, int, int>;

string S, A;
map<sii, int> M;

int dfs(int idx, int cur) {
	if (idx >= A.size()) {
		return 0;
	}
	auto it = M.find({S, idx, cur});
	if (it != M.end()) {
		return it->second;
	}
	int ret = 1e9;
	for (int i = cur - 1; i >= 0; i--) {
		if (A[idx] != S[i]) continue;
		char t = '0';
		swap(t, S[i]);
		ret = min(ret, dfs(idx + 1, i) + abs(cur - i));
		swap(t, S[i]);
		break;
	}

	for (int i = cur; i < S.size(); i++) {
		if (A[idx] != S[i]) continue;
		char t = '0';
		swap(t, S[i]);
		ret = min(ret, dfs(idx + 1, i) + abs(cur - i));
		swap(t, S[i]);
		break;
	}

	return M[{S, idx, cur}] = ret + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	A = S;
	sort(A.begin(), A.end());
	cout << dfs(0, 0) << '\n';
	return 0;
}