#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M, L;
pair<int, int> T;
vector<pair<int, int>> S;
vector<pair<int, int>> D;
int A[21][21];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool visit[21][21];

tuple<int, int, int> bfs(bool isDest = false, pair<int, int> dest = {0, 0}) {
	for (int i = 0; i <= N; i++)
		fill(visit[i], visit[i] + N + 1, false);
	vector<tuple<int, int, int>> v;
	queue<pair<int, int>> q;
	int cnt = 0;
	q.push(T);
	visit[T.first][T.second] = true;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			auto p = q.front(); q.pop();
			if (!isDest) {
				for (int j = 0; j < S.size(); j++) {
					if (p.first == S[j].first && p.second == S[j].second) {
						v.push_back({p.first, p.second, j});
					}
				}
			} else {
				if (p.first == dest.first && p.second == dest.second) {
					return {p.first, p.second, cnt};
				}
			}

			for (int j = 0; j < 4; j++) {
				int nx = p.second + dx[j];
				int ny = p.first + dy[j];
				if (1 > nx || nx > N || 1 > ny || ny > N) continue;
				if (A[ny][nx] == 1 || visit[ny][nx]) continue;
				visit[ny][nx] = true;
				q.push({ny, nx});
			}
		}
		if (v.size() > 0)
			break;
		cnt++;
	}
	if (v.size() > 0) {
		sort(v.begin(), v.end());
		T = {get<0>(v[0]), get<1>(v[0])};
		int y = D[get<2>(v[0])].first;
		int x = D[get<2>(v[0])].second;
		S.erase(S.begin() + get<2>(v[0]));
		D.erase(D.begin() + get<2>(v[0]));
		return {y, x, cnt};
	}
	return {-1, -1, -1};
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> L;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	cin >> T.first >> T.second;
	for (int i = 0; i < M; i++) {
		int sY, sX, dY, dX;
		cin >> sY >> sX >> dY >> dX;
		S.push_back({sY, sX});
		D.push_back({dY, dX});
	}

	while (S.size() > 0) {
		auto [dY, dX, sCnt] = bfs();
		if (dY == -1 && dX == -1 && sCnt == -1) {
			cout << "-1\n";
			return 0;
		}
		L -= sCnt;
		if (L <= 0) {
			cout << "-1\n";
			return 0;
		}
		auto [sY, sX, dCnt] = bfs(true, {dY, dX});
		if (sY == -1 && sX == -1 && dCnt == -1) {
			cout << "-1\n";
			return 0;
		}
		L -= dCnt;
		if (L < 0) {
			cout << "-1\n";
			return 0;
		}
		L += dCnt * 2;
		T = {sY, sX};
	}
	cout << L << '\n';

	return 0;
}