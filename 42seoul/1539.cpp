#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N;
int arr[250001];
set<int> s;
long long answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		set<int>::iterator it = s.lower_bound(num);
		
		if (s.empty())
			arr[num] = 1;
		else if (it == s.begin())
			arr[num] = arr[*it] + 1;
		else if (it == s.end())
			arr[num] = arr[*(--it)] + 1;
		else
		{
			int a = *it, b = *(--it);
			arr[num] = max(arr[a], arr[b]) + 1;
		}
		s.insert(num);
	}
	for (int i = 0; i < N; i++)
		answer += arr[i];
	cout << answer << '\n';
	return 0;
}