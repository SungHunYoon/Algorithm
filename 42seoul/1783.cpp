#include <iostream>

using namespace std;

int N, M;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int answer = 0;
	if (N == 1)
		answer = 1;
	else if (N == 2)
		answer = M >= 8 ? 4 : (M / N) + (M % N);
	else
		answer = M <= 4 ? M : M <= 5 ? M - 1 : M - 2;
	cout << answer << '\n';
	return 0;
}
