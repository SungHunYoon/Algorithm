#include <iostream>

using namespace std;

int D, N;
int A[300001];
int B[300001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> D >> N;
	for (int i = 1; i <= D; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	int prev = 0, end = D, answer = D + 1;
	for (int i = 0; i < N; i++) {
		if (prev >= B[i]) {
			end--;
			answer--;
			continue;
		}
		bool flag = false;
		for (int j = 1; j <= end; j++) {
			if (A[j] < B[i]) {
				answer = j - 1;
				end = j - 2;
				flag = true;
				break;
			}
		}
		if (!flag) {
			answer--;
			end--;
		}
		prev = B[i];
	}
	cout << (answer < 0 ? 0 : answer) << '\n';
	return 0;
}