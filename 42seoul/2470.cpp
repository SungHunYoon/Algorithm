#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	pair<int, int> answer;
	int value = 2e9 + 1;
	int start = 0, end = N - 1;
	while (start < end) {
		int sum = A[start] + A[end];
		if (abs(sum) < abs(value)) {
			value = sum;
			answer = {A[start], A[end]};
		}
		if (sum == 0)
			break;
		else if (sum > 0)
			end--;
		else 
			start++;
	}
	cout << answer.first << " " << answer.second << '\n';
	return 0;
}