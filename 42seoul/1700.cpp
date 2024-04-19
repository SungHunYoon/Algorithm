#include <iostream>
#include <set>
#include <climits>

using namespace std;

int N, K;
int arr[101];
int cnt[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	set<int> s;
	int answer = 0;
	for (int i = K - 1; i >= 0; i--)
	{
		if (N > s.size())
			s.insert(arr[i]);
		else
		{
			auto it = s.find(arr[i]);
			if (it != s.end())
				continue;
			int maxIndex = -1;
			int maxValue = 0;
			for (auto iter = s.begin(); iter != s.end(); iter++)
			{
				int idx = 0;
				for (int j = i - 1; j >= 0; j--, idx++)
				{
					if (*iter == arr[j])
					{
						if (maxIndex < idx)
						{
							maxIndex = idx;
							maxValue = *iter;
						}
						break;
					}
				}
				if (idx == i)
				{
					maxIndex = idx;
					maxValue = *iter;
				}
			}
			s.erase(maxValue);
			s.insert(arr[i]);
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}
