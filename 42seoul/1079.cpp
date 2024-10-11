#include <iostream>

using namespace std;

int N, C;
int A[16];
int R[16][16];
bool visit[16];
int answer;

void dfs(int n, int cnt) {
	answer = max(answer, cnt);
	if (n <= 1) return;
	if (n % 2) {
		int maxA = -1e9, idx = 0;
		for (int i = 0; i < N; i++) {
			if (!visit[i] && maxA < A[i]) {
				maxA = A[i];
				idx = i;
			}
		}
		if (idx == C) return;
		visit[idx] = true;
		dfs(n - 1, cnt);
		visit[idx] = false;
	} else {
		for (int i = 0; i < N; i++) {
			if (!visit[i] && i != C) {
				visit[i] = true;
				for (int j = 0; j < N; j++)
					A[j] += R[i][j];
				dfs(n - 1, cnt + 1);
				for (int j = 0; j < N; j++)
					A[j] -= R[i][j];
				visit[i] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> R[i][j];
	cin >> C;
	dfs(N, 0);
	cout << answer << '\n';
	return 0;
}