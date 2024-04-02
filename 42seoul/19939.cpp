#include <iostream>

using namespace std;

int N, K;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	int sum = K;
	for (int i = 0; i < K; i++)
		sum += i;
	if (sum > N)
		cout << "-1\n";
	else
	{
		int answer = (N - sum) / K + (K - 1) - (N - sum) / K;
		if ((N - sum) % K != 0)
			answer++;
		cout << answer << '\n';
	}
	return 0;
}

// 12 4
// 1 2 4 5
// 2 3 4 5