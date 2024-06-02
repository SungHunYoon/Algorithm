#include <iostream>

using namespace std;

int T, N, M, A, B;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
			cin >> A >> B;
		cout << N - 1 << '\n';
	}

	return 0;
}