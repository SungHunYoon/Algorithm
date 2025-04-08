#include <iostream>
#include <map>

using namespace std;

int N, M, K;
string A[10];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
map<string, int> D;

int dfs(string &target, string &current, int x, int y) {
	if (target.size() <= current.size()) {
		if (target.back() == current.back())
			return 1;
		else
			return 0;
	}
	if (target[current.size() - 1] != current[current.size() - 1])
		return 0;
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		int nx = (x + dx[i] + N) % N;
		int ny = (y + dy[i] + M) % M;
		if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
		current.push_back(A[nx][ny]);
		ret += dfs(target, current, nx, ny);
		current.pop_back();
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < K; i++) {
		string B;
		cin >> B;
		int answer = 0;
		auto it = D.find(B);
		if (it == D.end()) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					string C = string(1, A[j][k]);
					answer += dfs(B, C, j, k);
				}
			}
			D.insert({B, answer});
		} else {
			answer = it->second;
		}
		cout << answer << '\n';
	}
	return 0;
}