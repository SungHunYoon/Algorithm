#include <iostream>

using namespace std;

int T, N;
int A[100001];
int C[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			char c; cin >> c;
			if (c == 'W')
				A[i] = 0;
			else
				A[i] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			char c; cin >> c;
			if (c == 'W')
				C[i] = 0;
			else
				C[i] = 1;
		}
		int W = 0, B = 0;
		for (int i = 0; i < N; i++)
		{
			if (A[i] == C[i])
				continue;
			if (A[i] == 0)
				W++;
			else
				B++;
		}
		if (W > B)
			cout << B + (W - B) << '\n';
		else if (W == B)
			cout << B << '\n';
		else
			cout << W + (B - W) << '\n';
	}
	return 0;
}