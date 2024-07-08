#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L, X;
vector<int> A;

int countRest(int d) {
	int cnt = 0;
	for (int i = 0; i < A.size() - 1; i++)
		cnt += (A[i + 1] - A[i] - 1) / d;
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> L;
	A.push_back(0); A.push_back(L);
	for (int i = 0; i < N; i++) {
		cin >> X;
		A.push_back(X);
	}
	sort(A.begin(), A.end());
	int answer = 1e9;
	int start = 1, end = L;
	while (start < end) {
		int mid = (start + end) / 2;
		int cnt = countRest(mid);
		if (cnt > M) {
			start = mid + 1;
		} else {
			answer = min(answer, mid);
			end = mid;
		}
	}
	cout << answer << '\n';
	return 0;
}