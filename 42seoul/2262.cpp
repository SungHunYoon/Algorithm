#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[257];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> v(arr, arr + N);
	int answer = 0;
	while (v.size() != 1)
	{
		int maxIdx = 0;
		int maxValue = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (maxValue < v[i])
			{
				maxValue = v[i];
				maxIdx = i;
			}
		}
        int diff;
        if (maxIdx == 0)
            diff = abs(v[maxIdx] - v[maxIdx + 1]);
        else if (maxIdx == v.size() - 1)
            diff = abs(v[maxIdx] - v[maxIdx - 1]);
        else
            diff = min(abs(v[maxIdx] - v[maxIdx - 1]), abs(v[maxIdx] - v[maxIdx + 1]));
        answer += diff;
        v.erase(v.begin() + maxIdx);
	}
	cout << answer << '\n';
	return 0;
}