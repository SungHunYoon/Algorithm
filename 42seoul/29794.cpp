#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, K;
int A[626853];
long B[201], P[201], L[201], F[201];
ii T[202];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
		T[i] = { B[i], i };
	}
	sort(T + 1, T + M + 1);
	for (int i = 1, j = 1; i <= 200; i++) {
		if (j + 1 <= M && i >= T[j + 1].first) {
			j++;
		}
		P[i] = T[j].second;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < K && A[i] + j < 200; j++) {
			L[A[i] + j]++;
		}
	}
	for (int i = 1; i <= 200; i++) {
		F[P[i]] += L[i];
	}
	long sum = 0;
	for (int i = 1; i <= M; i++) {
		sum += F[i] * (i - 1);
	}
	long a, b, minSum = 1e18;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == j) continue;
			long portal = 0;
			for (int k = 1; k <= M; k++) {
				portal += F[k] * min(k - 1, (i - 1) + abs(j - k));
			}
			if (minSum > portal) {
				a = i, b = j;
				minSum = portal;
			}
		}
	}
	cout << a << " " << b << '\n';
	cout << sum - minSum << '\n';
	return 0;
}