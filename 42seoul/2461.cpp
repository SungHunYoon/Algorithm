#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[1001][1001];
int S[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
		sort(&A[i][1], &A[i][1] + M);
		S[i] = 1;
	}
	int maxIdx = 1, answer = 2e9;
	while (maxIdx <= M) {
		int maxV = 0, minV = 2e9, mIdx = 0;
		for (int i = 1; i <= N; i++) {
			maxV = max(maxV, A[i][S[i]]);
			if (minV > A[i][S[i]]) {
				minV = A[i][S[i]];
				mIdx = i;
			}
		}
		S[mIdx]++;
		answer = min(answer, maxV - minV);
		maxIdx = max(maxIdx, S[mIdx]);
	}
	cout << answer << '\n';
	return 0;
}