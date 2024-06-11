#include <iostream>
#include <vector>

using namespace std;

int N;
int A[51][9];
int T[9];
bool visit[9];
int answer;

void comb(vector<int> &v, int idx)
{
	if (idx >= 9)
	{
		int score = 0;
		int batter = 0;
		for (int i = 0; i < N; i++)
		{
			int outCnt = 0;
			int base = 0;
			while (outCnt < 3)
			{
				int result = A[i][v[batter]];
				batter++;
				if (batter >= 9)
					batter = 0;
				if (result == 0)
				{
					outCnt++;
					continue;
				}
				else if (result == 1)
				{
					if (base != 0)
						base <<= 1;
					base |= 1;
				}
				else if (result == 2)
				{
					if (base != 0)
						base <<= 2;
					base |= 2;
				}
				else if (result == 3)
				{
					if (base != 0)
						base <<= 3;
					base |= 4;
				}
				else
				{
					if (base != 0)
						base <<= 4;
					base |= 8;
				}

				int bitCal = (base & 0xFFFFFFF8) >> 3;
				for (int j = bitCal; j > 0; j >>= 1)
				{
					if (j & 0x01)
						score++;
				}
				base &= 0x07;
			}
		}
		answer = max(answer, score);
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v[i] = idx;
			comb(v, idx + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 9; j++)
			cin >> A[i][j];
	vector<int> v(9);
	visit[3] = true;
	v[3] = 0;
	comb(v, 1);
	cout << answer << '\n';
	return 0;
}