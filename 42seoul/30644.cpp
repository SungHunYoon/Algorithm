#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N;
int A[200001];
map<int, int> T;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		T[A[i]] = i;
	}
	sort(A + 1, A + N + 1);
	int answer = 0;
	int last = 1e9;
	for (int i = 1; i <= N; i++) {
		int idx = T[A[i]];
		if (last == 1e9 || abs(last - idx) == 1) {
			last = idx;
		} else {
			last = idx;
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}