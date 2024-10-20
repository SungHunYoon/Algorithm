#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[9], B[9];
bool V[9];
int answer;

void dfs(int idx) {
	if (idx >= N) {
		answer = max(answer, (int)count(V, V + N, true));
		return;
	}
	if (V[idx] || count(V, V + N, true) == N - 1) {
		dfs(idx + 1);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (idx == i) continue;
		if (!V[i]) {
			A[idx] -= B[i];
			A[i] -= B[idx];
			if (A[idx] <= 0) V[idx] = true;
			if (A[i] <= 0) V[i] = true;
			dfs(idx + 1);
			A[i] += B[idx];
			A[idx] += B[i];
			V[idx] = false;
			V[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i];
	dfs(0);
	cout << answer << '\n';
	return 0;
}