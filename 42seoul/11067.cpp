#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int T, N, M, X, Y;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> V[100001];
		for (int i = 0; i < N; i++) {
			cin >> X >> Y;
			V[X].push_back(Y);
		}
		vector<ii> answer;
		int prevY = 0, x = 0;
		while (answer.size() < N) {
			while (V[x].empty()) x++;
			sort(V[x].begin(), V[x].end());
			if (V[x].front() != prevY)
				reverse(V[x].begin(), V[x].end());
			for (auto ny : V[x])
				answer.push_back({x, ny});
			prevY = V[x].back();
			x++;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> X;
			auto &[x, y] = answer[X - 1];
			cout << x << " " << y << '\n';
		}
	}

	return 0;
}