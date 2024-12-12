#include <iostream>

using namespace std;

int N, K;
int A[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int s = 1, e = 1, oCnt = 0, eCnt = 0, answer = 0;
	while (e <= N) {
		if (A[e] % 2) oCnt++;
		else eCnt++;
		while (oCnt > K) {
			if (A[s] % 2) oCnt--;
			else eCnt--;
			s++;
		}
		e++;
		answer = max(answer, eCnt);
	}
	cout << answer << '\n';
	return 0;
}