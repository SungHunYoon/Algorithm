#include <iostream>

using namespace std;

string S;
long D[40];

long dfs(int idx) {
	if (idx >= S.size())
		return 1;
	if (D[idx])
		return D[idx];
	long ret = 0;
	string sub;
	for (int i = idx; i < S.size(); i++) {
		sub.append(1, S[i]);
		if (sub[0] == '0' || stoi(sub) > 34)
			break;
		ret += dfs(i + 1);
	}
	D[idx] = ret;
	return D[idx];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	cout << dfs(0) << '\n';
	return 0;
}