#include <iostream>

using namespace std;

int C;
int A[12][12];
bool visit[12];
int answer;

void dfs(int idx, int val) {
	if (idx >= 11) {
		answer = max(answer, val);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (A[idx][i] != 0 && !visit[i]) {
			visit[i] = true;
			dfs(idx + 1, val + A[idx][i]);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> C;
	while (C--) {
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> A[i][j];
		answer = 0;
		dfs(0, 0);
		cout << answer << '\n';
	}

	return 0;
}