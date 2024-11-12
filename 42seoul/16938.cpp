#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int N, L, R, X;
int A[15];
int answer;

void dfs(int idx, vector<int> &v) {
	if (idx >= N) {
		if (v.size() >= 2) {
			int sum = accumulate(v.begin(), v.end(), 0);
			if (L <= sum && sum <= R && v[v.size() - 1] - v[0] >= X) {
				answer++;
			}
		}
		return;
	}
	dfs(idx + 1, v);
	v.push_back(A[idx]);
	dfs(idx + 1, v);
	v.pop_back();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	vector<int> v;
	dfs(0, v);
	cout << answer << '\n';
	return 0;
}