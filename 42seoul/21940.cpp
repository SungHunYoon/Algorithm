#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int A[201][201];
int B[201];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	fill(&A[0][0], &A[201][0], 1e9);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		A[a][b] = c;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> B[i];
	for (int i = 1; i <= N; i++)
		A[i][i] = 0;
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
	vector<int> answer;
	int minT = 1e9;
	for (int i = 1; i <= N; i++) {
		int T = 0;
		for (int j = 0; j < K; j++)
			T = max(T, A[B[j]][i] + A[i][B[j]]);
		if (minT > T) {
			answer.clear();
			minT = T;
		}
		if (minT == T)
			answer.push_back(i);
	}
	for (auto v : answer)
		cout << v << ' ';
	cout << '\n';
	return 0;
}