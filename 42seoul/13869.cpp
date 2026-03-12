#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	deque<int> dq1, dq2;
	bool isLeft = false;
	for (int i = 1; i <= N; i++) {
		if (isLeft) {
			dq1.push_back(A[i]);
			dq2.push_front(A[i]);
		} else {
			dq1.push_front(A[i]);
			dq2.push_back(A[i]);
		}
		isLeft = !isLeft;
	}
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++) {
		sum1 += dq1[i] * dq1[(i + 1) % N];
		sum2 += dq2[i] * dq2[(i + 1) % N];
	}
	cout.precision(3);
	cout << fixed << 0.5 * sin((2 * acos(-1)) / N) * max(sum1, sum2) << '\n';
	return 0;
}