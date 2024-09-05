#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, K, N, D;
bool visit[1001];

void rotateGear(vector<vector<int>> &A, int idx, int dir) {
	visit[idx] = true;
	if (idx - 1 >= 0 && !visit[idx - 1] && A[idx - 1][2] != A[idx][6])
		rotateGear(A, idx - 1, dir == 1 ? -1 : 1);
	if (idx + 1 < T && !visit[idx + 1 ] && A[idx + 1][6] != A[idx][2])
		rotateGear(A, idx + 1, dir == 1 ? -1 : 1);
	if (dir == -1)
		rotate(A[idx].begin(), A[idx].begin() + 1, A[idx].end());
	else
		rotate(A[idx].begin(), A[idx].end() - 1, A[idx].end());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	vector<vector<int>> A(T, vector<int>(8, 0));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			char c;
			cin >> c;
			A[i][j] = c - '0';
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> D;
		N--;
		fill(visit, visit + T, false);
		rotateGear(A, N, D);
	}
	int answer = 0;
	for (int i = 0; i < A.size(); i++)
		if (A[i][0] == 1)
			answer++;
	cout << answer << '\n';
	return 0;
}