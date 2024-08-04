#include <iostream>
#include <algorithm>

using namespace std;

int X, N;
int A[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> X) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		sort(A, A + N);
		X *= 1e7;
		int start = 0, end = N - 1;
		pair<int, int> p = {-1, -1};
		while (start < end) {
			long t = A[start] + A[end];
			if (t == X) {
				p = {A[start], A[end]};
				break;
			}
			if (t < X)
				start++;
			else
				end--;
		}
		if (p.first == -1 && p.second == -1)
			cout << "danger\n";
		else
			cout << "yes " << p.first << " " << p.second << '\n';
	}

	return 0;
}