#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using ici = tuple<int, char, int>;

int T[2], N;
int D[2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T[0] >> T[1] >> N;
	queue<ici> q;
	for (int i = 0; i < N; i++) {
		int a, c;
		char b;
		cin >> a >> b >> c;
		q.push({a, b, c});
	}
	queue<int> dQ[2];
	vector<int> answer[2];
	int i = 1, gift = 1;
	while (1) {
		if (!q.size() && !dQ[0].size() && !dQ[1].size() && !D[0] && !D[1])
			break;
		if (!q.empty()) {
			auto [time, color, cnt] = q.front();
			if (i >= time) {
				int idx = (color == 'R' ? 1 : 0);
				for (int j = 0; j < cnt; j++) {
					dQ[idx].push(time);
				}
				q.pop();
			}
		}
		for (int j = 0; j < 2; j++) {
			if (D[j]) continue;
			while (!D[j] && !dQ[j].empty()) {
				dQ[j].pop();
				D[j] = T[j];
				answer[j].push_back(gift++);
			}
		}
		for (int j = 0; j < 2; j++)
			D[j] = max(D[j] - 1, 0);
		i++;
	}
	for (int i = 0; i < 2; i++) {
		cout << answer[i].size() << '\n';
		for (auto a : answer[i])
			cout << a << ' ';
		cout << '\n';
	}
	return 0;
}