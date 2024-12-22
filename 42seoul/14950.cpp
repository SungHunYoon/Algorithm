#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
int N, M, T, A, B, C;
vector<ii> V[10001];
bool D[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		V[A].push_back({C, B});
		V[B].push_back({C, A});
	}
	int answer = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, 1});
	int inc = 0;
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (D[n]) continue;
		D[n] = true;
		answer += d + inc;
		for (auto [nD, nN] : V[n])
			pq.push({nD, nN});
		if (n != 1) inc += T;
	}
	cout << answer << '\n';
	return 0;
}