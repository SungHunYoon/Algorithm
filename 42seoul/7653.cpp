#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[4][4001];
vector<long> B[2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 4; j++)
			cin >> A[j][i];
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				B[i].push_back(A[i * 2][j] + A[i * 2 + 1][k]);
		sort(B[i].begin(), B[i].end());
	}
	long answer = 0;
	for (auto b : B[0]) {
		auto [s, e] = equal_range(B[1].begin(), B[1].end(), -b);
		answer += e - s;
	}
	cout << answer << '\n';
	return 0;
}