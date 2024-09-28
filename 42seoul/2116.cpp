#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[10001][6];
int M[6] = { 5, 3, 4, 1, 2, 0 };

int maxNumber(int idx, int b, int t) {
	int maxValue = 0;

	for (int i = 0; i < 6; i++) {
		if (A[idx][i] == b || A[idx][i] == t)
			continue;
		maxValue = max(maxValue, A[idx][i]);
	}
	return maxValue;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 6; j++)
			cin >> A[i][j];
	int answer = 0;
	for (int i = 0; i < 6; i++) {
		int b = A[0][i], t = A[0][M[i]], sum = maxNumber(0, b, t);
		for (int j = 1; j < N; j++) {
			int newB = t;
			int newT = A[j][M[find(A[j], A[j] + 6, t) - A[j]]];
			sum += maxNumber(j, newB, newT);
			b = newB;
			t = newT;
		}
		answer = max(answer, sum);
	}
	cout << answer << '\n';
	return 0;
}
