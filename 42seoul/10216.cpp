#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int T, N, X, Y, R;
int P[3001];
iii A[5001];

int find(int idx) {
	if (idx == P[idx])
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b)
		P[a] = b;
	else
		P[b] = a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			P[i] = i;
		for (int i = 1; i <= N; i++) {
			cin >> X >> Y >> R;
			A[i] = tie(X, Y, R);
			for (int j = 1; j < i; j++) {
				if (pow(R + get<2>(A[j]), 2) >= pow(X - get<0>(A[j]), 2) + pow(Y - get<1>(A[j]), 2)) {
					make_union(i, j);
				}
			}
		}
		int C[3001] = { 0, };
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			if (C[find(i)] == 0) {
				C[find(i)]++;
				answer++;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}