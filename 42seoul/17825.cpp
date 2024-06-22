#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[10];
int S[33];
vector<int> V[33];
int P[4];
int answer;

void makeMap()
{
	for (int i = 0; i < 20; i++)
		V[i].push_back(i + 1);
	V[20].push_back(32);

	V[5].push_back(21);
	for (int i = 21; i < 23; i++)
		V[i].push_back(i + 1);
	V[23].push_back(29);

	V[10].push_back(24);
	V[24].push_back(25);
	V[25].push_back(29);

	V[15].push_back(26);
	for (int i = 26; i < 31; i++)
		V[i].push_back(i + 1);
	V[31].push_back(20);

	for (int i = 1, s = 2; i <= 20; i++, s += 2)
		S[i] = s;
	for (int i = 21, s = 13; i <= 23; i++, s += 3)
		S[i] = s;
	for (int i = 24, s = 22; i <= 25; i++, s += 2)
		S[i] = s;
	for (int i = 26, s = 28; i <= 28; i++, s--)
		S[i] = s;
	for (int i = 29, s = 25; i <= 31; i++, s += 5)
		S[i] = s;
}

int nextScore(int idx, int cnt, bool flag = false)
{
	if (cnt <= 0 || idx >= 32)
	{
		if (idx < 32)
		{
			for (int i = 0; i < 4; i++)
				if (P[i] == idx)
					return 0;
		}
		return idx;
	}
	if (flag && (idx == 5 || idx == 10 || idx == 15))
		return nextScore(V[idx][1], cnt - 1);
	else
		return nextScore(V[idx][0], cnt - 1);
}

void dfs(int idx, int val)
{
	if (idx >= 10)
	{
		answer = max(answer, val);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (P[i] < 32)
		{
			int tmp = nextScore(P[i], A[idx], true);
			if (tmp > 0)
			{
				int prev = P[i];
				P[i] = tmp;
				dfs(idx + 1, val + S[P[i]]);
				P[i] = prev;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 10; i++)
		cin >> A[i];
	makeMap();
	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}