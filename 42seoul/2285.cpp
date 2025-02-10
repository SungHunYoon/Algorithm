#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
ii A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	long total = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
		total += A[i].second;
	}
	sort(A, A + N);
	int answer = 0;
	long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i].second;
		if ((total + 1) / 2 <= sum) {
			answer = A[i].first;
			break;
		}
	}
	cout << answer << '\n';
	return 0;
}