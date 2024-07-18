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
	int start = 0, end = N - 1;
	int answer = 0;
	while (start < end) {
		//cout << start << " " << end << " ";
		int tmp = A[start] + A[end];
		if (tmp == 0) {
			answer = 0;
			break;
		}
		else if (tmp < 0) {
			if (answer == 0 || abs(answer) > abs(tmp))
				answer = tmp;
			start++;
		} else {
			if (answer == 0 || abs(answer) > abs(tmp))
			answer = tmp;
			end--;
		}
		//cout << answer << '\n';
	}
	cout << answer << '\n';
	return 0;
}