#include <iostream>

using namespace std;

int N, B, W;
char A[300001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B >> W;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int s = 1, e = 1, wCnt = 0, bCnt = 0, answer = 0;
	while (e <= N) {
		if (A[e] == 'W') {
			wCnt++;
		} else {
			bCnt++;
		}
		while (bCnt > B) {
			if (A[s] == 'W') {
				wCnt--;
			}
			else {
				bCnt--;
			}
			s++;
		}
		if (wCnt >= W && bCnt <= B)
			answer = max(answer, wCnt + bCnt);
		e++;
	}
	cout << answer << '\n';
	return 0;
}