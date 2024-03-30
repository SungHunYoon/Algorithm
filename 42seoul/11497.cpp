#include <iostream>
#include <algorithm>

using namespace std;

int T, N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int L[N];
		for (int j = 0; j < N; j++)
			cin >> L[j];
		sort(L, L + N);
		int answer = 0;
		for (int j = 2; j < N; j++)
			answer = max(answer, L[j] - L[j - 2]);
		cout << answer << '\n';
	}
	return 0;
}

// 10 10 11 11 12 12 13
// 10 11 12 13
// 10 11 12

// 2 4 5 7 9
// 2 5 9
// 4 7