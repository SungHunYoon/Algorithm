#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int m[51];
int p[51];
int mIndex;
int pIndex;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num < 0)
			m[mIndex++] = num;
		else
			p[pIndex++] = num;
	}
	sort(m, m + mIndex);
	sort(p, p + pIndex, greater<int>());
	int answer = 0;
	if (mIndex > 0 && pIndex <= 0)
	{
		answer += abs(m[0]);
		for (int i = M; i < mIndex; i += M)
			answer += abs(m[i]) * 2;
	}
	else if (mIndex <= 0 && pIndex > 0)
	{
		answer += p[0];
		for (int i = M; i < pIndex; i += M)
			answer += p[i] * 2;
	}
	else if (abs(m[0]) > p[0])
	{
		answer += abs(m[0]);
		for (int i = M; i < mIndex; i += M)
			answer += abs(m[i]) * 2;
		for (int i = 0; i < pIndex; i += M)
			answer += p[i] * 2;
	}
	else
	{
		answer += p[0];
		for (int i = M; i < pIndex; i += M)
			answer += p[i] * 2;
		for (int i = 0; i < mIndex; i += M)
			answer += abs(m[i]) * 2;
	}
	cout << answer << '\n';
	return 0;
}
