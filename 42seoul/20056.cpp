#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using Fireball = tuple<int, int, int, int, int>;

int N, M, K;
vector<int> A[51][51];
vector<Fireball> F;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void printFireBall() {
	cout << "=========================\n";
	for (int i = 0; i < F.size(); i++) {
		cout << i << " : " << get<0>(F[i]) << " " << get<1>(F[i]) << " " << get<2>(F[i]) << " " << get<3>(F[i]) << " " << get<4>(F[i]) << '\n';
	}
}

void moveFireball() {
	for (int i = 0; i < F.size(); i++) {
		get<1>(F[i]) += dx[get<3>(F[i])] * get<4>(F[i]);
		get<0>(F[i]) += dy[get<3>(F[i])] * get<4>(F[i]);
		if (get<1>(F[i]) > N) {
			get<1>(F[i]) %= N;
			if (get<1>(F[i]) == 0)
				get<1>(F[i]) = N;
		}
		else {
			while (get<1>(F[i]) <= 0)
				get<1>(F[i]) += N;
		}
		if (get<0>(F[i]) > N) {
			get<0>(F[i]) %= N;
			if (get<0>(F[i]) == 0)
				get<0>(F[i]) = N;
		}
		else {
			while (get<0>(F[i]) <= 0)
				get<0>(F[i]) += N;
		}
		A[get<0>(F[i])][get<1>(F[i])].push_back(i);
	}
}

void mergeFireball() {
	vector<Fireball> nF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j].size() < 2) {
				for (int k = 0; k < A[i][j].size(); k++)
					nF.push_back(F[A[i][j][k]]);
				A[i][j].clear();
				continue;
			}
			int s = 0;
			int m = 0;
			int d = -1;
			bool flag = true;
			for (int k = 0; k < A[i][j].size(); k++) {
				m += get<2>(F[A[i][j][k]]);
				s += get<4>(F[A[i][j][k]]);
				if (d == -1)
					d = get<3>(F[A[i][j][k]]) % 2;
				else {
					if (flag) {
						if (d != get<3>(F[A[i][j][k]]) % 2)
							flag = false;
					}
				}
			}
			m /= 5;
			s /= A[i][j].size();
			A[i][j].clear();
			if (m != 0) {
				for (int k = 0; k < 4; k++)
					nF.push_back({i, j, m, flag ? k * 2 : k * 2 + 1, s});
			}
		}
	}
	F = nF;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, d, s;
		cin >> r >> c >> m >> s >> d;
		F.push_back({r, c, m, d, s});
	}
	
	while (K--) {
		moveFireball();
		//printFireBall();
		mergeFireball();
		//printFireBall();
	}
	int answer = 0;
	for (int i = 0; i < F.size(); i++)
		answer += get<2>(F[i]);
	cout << answer << '\n';
	return 0;
}