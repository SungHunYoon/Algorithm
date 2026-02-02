#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[5];
int T[5] = {4, 6, 8, 12, 20};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int sum = 0, total = 0;
	for (int i = 0; i < 5; i++) {
		cin >> A[i];
		sum += T[i] * A[i];
		total += A[i];
	}
	vector<int> answer;
	int L = total, R = sum;
	while (L < R) {
		answer.push_back(L++);
		answer.push_back(R--);
	}
	if (L == R) {
		answer.push_back(L);
	}

	reverse(answer.begin(), answer.end());

	for (int a : answer) {
		cout << a << ' ';
	}
	cout << '\n';
	return 0;
}