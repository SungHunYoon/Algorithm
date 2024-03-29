#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string strs[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> strs[i];
	string answer;
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		// A, C, G, T
		int newcleo[4] = {0, 0, 0, 0};
		for (int j = 0; j < N; j++)
		{
			if (strs[j][i] == 'A')
				newcleo[0]++;
			else if (strs[j][i] == 'C')
				newcleo[1]++;
			else if (strs[j][i] == 'G')
				newcleo[2]++;
			else
				newcleo[3]++;
		}
		int index = max_element(newcleo, newcleo + 4) - newcleo;
		if (index == 0)
			answer.append(1, 'A');
		else if (index == 1)
			answer.append(1, 'C');
		else if (index == 2)
			answer.append(1, 'G');
		else
			answer.append(1, 'T');
		cnt += N - newcleo[index];
	}
	cout << answer << '\n';
	cout << cnt << '\n';
	return 0;
}

// AAAGATCC
// TAAGATGT
// TAAGCTAC
// TATGATAC
// TGAGATAC
