#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int M, N;
vector<ii> A[101];
map<vector<ii>, int> P;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int v;
			cin >> v;
			A[i].push_back({v, j});
		}
		sort(A[i].begin(), A[i].end());
		vector<ii> T;
		for (int j = 0; j < N; j++) {
			if (j == 0)
				T.push_back({A[i][j].second, 0});
			else {
				int sign = A[i][j - 1].first - A[i][j].first == 0 ? 0 : -1;
				T.push_back({A[i][j].second, sign});
			}
		}
		P[T]++;
	}
	int answer = 0;
	for (auto [v, c] : P) {
		while (c)
			answer += --c;
	}
	cout << answer << '\n';
	return 0;
}