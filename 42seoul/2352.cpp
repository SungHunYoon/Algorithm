#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[40001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		if (answer.empty() || answer.back() < A[i])
			answer.push_back(A[i]);
		else {
			auto it = lower_bound(answer.begin(), answer.end(), A[i]);
			*it = A[i];
		}
	}
	cout << answer.size() << '\n';

	return 0;
}