#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int A, B, C;
int avg;
int P[3][2] = {{0, 1}, {0, 2}, {1, 2}};
set<vector<int>> S;

bool dfs(vector<int> v) {
	if (v[0] == v[1] && v[1] == v[2])
		return true;
	// cout << v[0] << " " << v[1] << " " << v[2] << '\n';
	if (!S.insert(v).second)
		return false;
	for (int i = 0; i < 3; i++) {
		vector<int> t = v;
		int minIdx, maxIdx;
		if (t[P[i][0]] == t[P[i][1]])
			continue;
		if (t[P[i][0]] > t[P[i][1]]) {
			maxIdx = P[i][0];
			minIdx = P[i][1];
		}
		else {
			maxIdx = P[i][1];
			minIdx = P[i][0];
		}
		if (t[minIdx] >= avg)
			continue;
		t[maxIdx] -= t[minIdx];
		t[minIdx] += t[minIdx];
		if (dfs(t))
			return true;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> C;
	vector<int> v;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	avg = (A + B + C) / 3;
	cout << dfs(v) << '\n';
	return 0;
}
