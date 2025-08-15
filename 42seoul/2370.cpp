#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
int L[10001], R[10001];
vector<int> A;

int findp(vector<int> &P, int x) {
	return (P[x] == x) ? x : P[x] = findp(P, P[x]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> R[i];
		A.push_back(L[i]);
		A.push_back(R[i]);
	}
	sort(A.begin(), A.end());
	auto it = unique(A.begin(), A.end());
	int M = it - A.begin();

	map<int, int> Midx;
	for (int i = 0; i < M; i++) {
		Midx[A[i]] = i + 1;
	}

	vector<int> Pg(M + 1);
	for (int i = 1; i <= M - 1; i++) {
		int gap = max(0, A[i] - A[i - 1] - 1);
		Pg[i] = (gap > 0) ? i : (i + 1);
	}
	Pg[M] = M;

	vector<int> Pp(M + 1 + 1);
	for (int i = 1; i <= M + 1; i++) {
		Pp[i] = i;
	}

	auto FINDg = [&](int x){ return findp(Pg, x); };
	auto FINDp = [&](int x){ return findp(Pp, x); };

	int answer = 0;
	for (int i = N; i >= 1; i--) {
		int l = Midx[L[i]];
		int r = Midx[R[i]];
		bool painted = false;
		int j = FINDg(l);

		while (j < r) {
			painted = true;
			Pg[j] = FINDg(j + 1);
			j = Pg[j];
		}
		int k = FINDp(l);
		while (k <= r) {
			painted = true;
			Pp[k] = FINDp(k + 1);
			k = Pp[k];
		}
		if (painted) ++answer;
	}
	cout << answer << '\n';
	return 0;
}