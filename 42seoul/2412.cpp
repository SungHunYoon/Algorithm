#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, T, X, Y;
set<ii> A;
map<ii, vector<ii>> M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		A.insert({X, Y});
	}
	A.insert({0, 0});
	for (auto [x, y] : A) {
		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				if (i == 0 && j == 0) continue;
				if (A.find({x + i, y + j}) != A.end()) {
					M[{x, y}].push_back({x + i, y + j});
					M[{x + i, y + j}].push_back({x, y});
				}
			}
		}
	}
	A.clear();
	queue<ii> q;
	A.insert({0, 0});
	q.push({0, 0});
	int cnt = 0;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			auto [x, y] = q.front(); q.pop();
			if (y == T) {
				cout << cnt << '\n';
				return 0;
			}
			for (auto [nx, ny] : M[{x, y}]) {
				if (!A.insert({nx, ny}).second) continue;
				q.push({nx, ny});
			}
		}
		cnt++;
	}
	cout << "-1\n";
	return 0;
}