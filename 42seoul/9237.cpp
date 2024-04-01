#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> T[i];
	sort(T, T + N, greater<int>());
	int answer = 0;
	for (int i = 0; i < N; i++)
		answer = max(answer, T[i] + (N - (N - i - 1)));
	cout << answer + 1 << '\n';
	return 0;
}

// 4 + (N - 3) (1) = 5
// 3 + (N - 2) (2) = 5
// 3 + (N - 1) (3) = 6
// 2 + (N) (4) = 6

// 4 3 3 2
// 3 3 3 2
// 2 2 3 2
// 1 1 2 2
// 0 0 1 1
// 0 0 0 0