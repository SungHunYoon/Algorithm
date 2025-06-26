#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int mx[] = {0, 1, 0, -1};
int my[] = {-1, 0, 1, 0};
int D[4];

void printArr() {
	cout << "===============\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

void useBlizard(int d, int s) {
	int nx, ny;
	nx = ny = (N + 1) / 2;
	for (int i = 0; i < s; i++) {
		nx += dx[d];
		ny += dy[d];
		A[nx][ny] = 0;
	}
}

vector<int> serializeBead() {
	int x, y;
	x = y = (N + 1) / 2;
	vector<int> ret;
	int std = 1, c = 0, cnt = 0, d = 0;
	while (!(x == 1 && y == 1)) {
		x += mx[d];
		y += my[d];
		if (A[x][y]) {
			ret.push_back(A[x][y]);
		}
		if (++c >= std) {
			c = 0;
			if (++cnt >= 2) {
				std++;
				cnt = 0;
			}
			if (++d >= 4) {
				d = 0;
			}
		}
	}
	return ret;
}

void deserializeBead(vector<int> &S) {
	int x, y;
	x = y = (N + 1) / 2;
	int std = 1, c = 0, cnt = 0, d = 0, idx = 0;
	while (!(x == 1 && y == 1)) {
		x += mx[d];
		y += my[d];
		if (idx < S.size()) {
			A[x][y] = S[idx++];
		} else {
			A[x][y] = 0;
		}
		if (++c >= std) {
			c = 0;
			if (++cnt >= 2) {
				std++;
				cnt = 0;
			}
			if (++d >= 4) {
				d = 0;
			}
		}
	}
}

void moveBead() {
	vector<int> S = serializeBead();
	deserializeBead(S);
}

bool calScore(vector<int> &S, int sIdx, int eIdx) {
	bool ret = false;
	if (eIdx - sIdx >= 4) {
		D[S[sIdx]] += eIdx - sIdx;
		ret = true;
		for (int i = sIdx; i < eIdx; i++) {
			S[i] = 0;
		}
	}
	return ret;
}

void checkBead() {
	bool flag = true;
	while (flag) {
		vector<int> S = serializeBead();
		int sIdx = 0, eIdx = 0;
		flag = false;
		for (int i = 0; i < S.size(); i++) {
			if (S[sIdx] != S[eIdx]) {
				flag = max(flag, calScore(S, sIdx, eIdx));
				sIdx = eIdx;
			}
			eIdx++;
		}
		flag = max(flag, calScore(S, sIdx, eIdx));
		deserializeBead(S);
	}
}

void mutateBead() {
	vector<int> S = serializeBead();
	vector<int> T;
	int sIdx = 0, eIdx = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[sIdx] != S[eIdx]) {
			T.push_back(eIdx - sIdx);
			T.push_back(S[sIdx]);
			sIdx = eIdx;
		}
		eIdx++;
	}
	if (sIdx != eIdx) {
		T.push_back(eIdx - sIdx);
		T.push_back(S[sIdx]);
	}
	deserializeBead(T);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	while (M--) {
		int d, s;
		cin >> d >> s;
		d--;
		useBlizard(d, s);
		moveBead();
		checkBead();
		mutateBead();
	}
	cout << D[1] * 1 + D[2] * 2 + D[3] * 3 << '\n';
	return 0;
}