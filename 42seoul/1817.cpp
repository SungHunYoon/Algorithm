#include <iostream>

using namespace std;

int N, M;
int A[51];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int box = 0;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (box + A[i] <= M)
		{
			if (box == 0)
				answer++;
			box += A[i];
		}
		else
		{
			box = A[i];
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}