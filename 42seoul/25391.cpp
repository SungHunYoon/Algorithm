#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, K;
ii A[200001];

bool descSecond(ii &a, ii &b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

bool descFirst(ii &a, ii &b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	long answer = 0;
	sort(A, A + N, descSecond);
	sort(A + K, A + N, descFirst);
	for (int i = 0; i < M + K; i++) {
		answer += A[i].first;
	}
	cout << answer << '\n';

	return 0;
}