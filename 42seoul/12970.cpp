#include <iostream>
#include <string>

using namespace std;

int N, K;
string str;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		str.append(1, 'B');
	int A = 0;
	int B = N;
	for (int i = 0; i < str.size(); i++)
	{
		if (K + A >= (B - 1) - i)
		{
			K -= (B - 1) - A - i;
			str[i] = 'A';
			B--;
			//cout << K << '\n';
			if (K == 0)
				break;
		}
	}
	if (K != 0)
		cout << "-1\n";
	else
		cout << str << '\n';
	return 0;
}