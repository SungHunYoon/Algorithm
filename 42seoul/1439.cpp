#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	char idx = 0;
	int zero = 0;
	int one = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (idx != S[i])
		{
			if (S[i] == '0')
				zero++;
			else
				one++;
		}
		idx = S[i];
	}
	cout << min(zero, one) << '\n';
	return 0;
}