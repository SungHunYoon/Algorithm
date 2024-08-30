#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	long answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int sum = -(A[i] + A[j]);
			auto it = lower_bound(A.begin() + j + 1, A.end(), sum);
			if (*it == sum) {
				auto it2 = upper_bound(it, A.end(), *it);
				if (it != it2)
					answer += distance(it, it2);
			}
		}
	}
	cout << answer << '\n';
	return 0;
}
