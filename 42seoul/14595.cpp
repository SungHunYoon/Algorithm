#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
ii A[5001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> A[i].first >> A[i].second;
	sort(A, A + M);
	int answer = 0;
	int value = 0;
	for (int i = 0; i < M; i++) {
		if (value < A[i].first) 
			answer += A[i].first - value;
		value = max(value, A[i].second);
	}
	answer += N - value;
	cout << answer << '\n';
	return 0;
}