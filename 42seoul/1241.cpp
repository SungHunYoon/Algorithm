#include <iostream>

using namespace std;

int N;
int A[100001];
int C[1000001];
int D[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		C[A[i]]++;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (!C[i]) continue;
		D[i] += C[i] - 1;
		for (int j = i + i; j <= 1000000; j += i) {
			D[j] += C[i];
		}
	}
	for (int i = 0; i < N; i++) {
		cout << D[A[i]] << '\n';
	}
	return 0;
}