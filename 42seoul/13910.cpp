#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;
int D[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s;
		cin >> s;
		A.push_back(s);
	}
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++)
			A.push_back(A[i] + A[j]);
	fill(D, D + N + 1, 1e9);
	D[0] = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = A[i]; j <= N; j++) {
			D[j] = min(D[j], D[j - A[i]] + 1);
		}
	}
	cout << (D[N] == 1e9 ? -1 : D[N]) << '\n';
	return 0;
}