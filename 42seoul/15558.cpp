#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, K;
int A[2][100001];
bool V[2][100001];
int dy[] = {-1, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < 2; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= N; j++)
			A[i][j] = S[j - 1] - '0';
	}
	queue<ii> q;
	q.push({0, 1});
	int T = 1;
	bool answer = false;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			auto [x, y] = q.front(); q.pop();
			if (T > y) continue;
			if (y >= N) {
				answer = true;
				continue;
			}
			for (int j = 0; j < 2; j++) {
				int ny = y + dy[j];
				if (!A[x][ny]) continue;
				if (V[x][ny]) continue;
				V[x][ny] = true;
				q.push({x , ny});
			}
			if (y + K > N && !V[!x][N]) {
				V[!x][N] = true;
				q.push({!x, N});
			} else if (A[!x][y + K] && !V[!x][y + K]) {
				V[!x][y + K] = true;
				q.push({!x, y + K});
			}
		}
		T++;
	}
	cout << answer << '\n';
	return 0;
}