#include <iostream>
#include <algorithm>

using namespace std;

int N, M, T, X, D, K;
int A[51][51];
bool visit[51][51];

void rotateCircle() {
	cin >> X >> D >> K;
	for (int i = X; i <= N; i++) {
		if (i % X != 0)
			continue;
		if (D == 0)
			rotate(A[i], A[i] + M - K, A[i] + M);
		else
			rotate(A[i], A[i] + K, A[i] + M);
	}
}

bool checkDistinct() {
	for (int i = 1; i <= N; i++)
		fill(visit[i], visit[i] + 51, false);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j]) {
				int prev = i - 1;
				int next = i + 1;
				if (prev > 0 && A[i][j] == A[prev][j])
					visit[i][j] = visit[prev][j] = true;
				if (next <= N && A[i][j] == A[next][j])
					visit[i][j] = visit[next][j] = true;
				prev = j - 1 < 0 ? M - 1 : j - 1;
				next = j + 1 >= M ? 0 : j + 1;
				if (A[i][j] == A[i][prev])
					visit[i][j] = visit[i][prev] = true;
				if (A[i][j] == A[i][next])
					visit[i][j] = visit[i][next] = true;
			}
		}
	}
	bool ret = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) {
				A[i][j] = 0;
				ret = true;
			}
		}
	}
	return ret;
}

void calculateAverage() {
	double avg = 0;
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j]) {
				avg += A[i][j];
				cnt++;
			}
		}
	}

	if (cnt == 0)
		return;

	avg /= cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j]) {
				if (A[i][j] > avg)
					A[i][j]--;
				else if (A[i][j] < avg)
					A[i][j]++;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	for (int i = 0; i < T; i++) {
		rotateCircle();
		if (!checkDistinct())
			calculateAverage();
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			answer += A[i][j];
	cout << answer << '\n';
	return 0;
}