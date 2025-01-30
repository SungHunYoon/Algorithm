#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A[101];
vector<int> B[2];
bool V[101];

void dfs(int idx, int rb) {
	B[rb].push_back(idx);
	V[idx] = true;
	for (auto i : A[idx]) {
		if (V[i]) continue;
		dfs(i, !rb);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int C;
		cin >> C;
		for (int j = 0; j < C; j++) {
			int P;
			cin >> P;
			A[i].push_back(P);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (V[i]) continue;
		bool flag = true;
		for (auto a : A[i]) {
			if (find(B[0].begin(), B[0].end(), a) != B[0].end()) {
				flag = false;
				break;
			}
		}
		if (flag) dfs(i, 0);
		else dfs(i, 1);
	}
	sort(B[0].begin(), B[0].end());
	sort(B[1].begin(), B[1].end());
	for (int i = 0; i < 2; i++) {
		cout << B[i].size() << '\n';
		for (auto b : B[i])
			cout << b << ' ';
		cout << '\n';
	}
	return 0;
}