#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> A[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i].first >> A[i].second;
	sort(A, A + N);
	long answer = 0;
	int start = -1e9 - 1, end = -1e9 -1;
	for (int i = 0; i < N; i++) {
		if (end >= A[i].first)
			end = max(end, A[i].second);
		else {
			answer += end - start;
			start = A[i].first;
			end = A[i].second;
		}
	}
	cout << answer + (end - start) << '\n';
	return 0;
}