#include <iostream>

using namespace std;

int N;
int A[1000001];
int B[20];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		for (int mask = 1, idx = 0; mask <= A[i]; mask <<= 1, idx++) {
			if (A[i] & mask) B[idx]++;
		}
	}
	long answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int mask = 1, idx = 0; idx < 20; mask <<= 1, idx++) {
			if (A[i] & mask) {
				B[idx]--;
				answer += (long)mask * (N - i - B[idx]);
			} else {
				answer += (long)mask * B[idx];
			}
		}
	}
	cout << answer << '\n';
	return 0;
}