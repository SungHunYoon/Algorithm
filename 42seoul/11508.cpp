#include <iostream>
#include <algorithm>

using namespace std;

int N;
int C[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> C[i];
	sort(C + 1, C + N + 1, greater<int>());
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i % 3 != 0)
			answer += C[i];
	}
	cout << answer << '\n';
	return 0;
}