#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000001];
int T[1000001];
int D[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		T[A[i]]++;
	}
	fill(D, D + N + 1, -1);
	for (int i = N - 1; i >= 0; i--) {
		if (T[A[i]] < T[A[i + 1]])
			D[i] = A[i + 1];
		else {
			for (int j = i + 1; j < N && D[j] != -1; j++) {
				if (T[A[i]] < T[D[j]]) {
					D[i] = D[j];
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << D[i] << ' ';
	cout << '\n';
	return 0;
}