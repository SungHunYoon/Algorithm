#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int T[100001];
int D[100001];
vector<int> V[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		D[y]++;
	}
	bool answer = true;
	while (K--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			if (D[b] > 0) {
				answer = false;
				break;
			}
			for (auto v : V[b]) {
				if (T[b] == 0)
					D[v]--;
			}
			T[b]++;
		} else {
			if (!T[b]) {
				answer = false;
				break;
			}
			for (auto v : V[b]) {
				if (T[b] == 1)
					D[v]++;
			}
			T[b]--;
		}
	}
	cout << (answer ? "King-God-Emperor" : "Lier!") << '\n';
	return 0;
}