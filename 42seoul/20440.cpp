#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
vector<ii> M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	while (N--) {
	int a, b;
	cin >> a >> b;
	M.push_back({a, 1});
	M.push_back({b, -1});
	}

	sort(M.begin(), M.end());

	int maxCnt = 0, minRange = 0, maxRange = 0, cnt = 0;
	for (int i = 0; i < M.size(); ++i) {
		auto [t, v] = M[i];
		cnt += v;

		while (i + 1 < M.size() && M[i + 1].first == t) {
			cnt += M[i + 1].second;
			++i;
		}
		if (cnt != maxCnt && minRange == maxRange)
			maxRange = M[i].first;

		if (cnt > maxCnt) {
			maxCnt = cnt;
			minRange = t;
			maxRange = t;
		}
	}

	cout << maxCnt << '\n' << minRange << ' ' << maxRange << '\n';
	return 0;
}