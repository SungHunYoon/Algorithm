#include <iostream>
#include <stack>

using namespace std;

int N;
bool D[1001][10];
int T[1001][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int M;
		cin >> M;
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			if (i == 1) {
				D[i][a] = true;
			} else {
				for (int k = 1; k <= 9; k++) {
					if (k == a) continue;
					if (!D[i - 1][k]) continue;
					D[i][a] = true;
					T[i][a] = k;
				}
			}
		}
	}
	stack<int> answer;
	for (int i = 1; i <= 9; i++) {
		if (!D[N][i]) continue;
		int day = N;
		int idx = i;
		answer.push(idx);
		while (T[day][idx]) {
			answer.push(T[day][idx]);
			idx = T[day][idx];
			day--;
		}
		break;
	}
	if (answer.size() != N) {
		cout << "-1\n";
		return 0;
	}
	while (!answer.empty()) {
		cout << answer.top() << '\n';
		answer.pop();
	}
	return 0;
}