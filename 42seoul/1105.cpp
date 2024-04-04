#include <iostream>
#include <string>

using namespace std;

string L, R;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> R;
	if (L.size() < R.size())
	{
		cout << "0\n";
		return 0;
	}
	int answer = 0;
	for (int i = 0; i < L.size(); i++)
	{
		if (L[i] != R[i])
			break;
        if (L[i] == '8')
		    answer++;
	}
	cout << answer << '\n';
	return 0;
}