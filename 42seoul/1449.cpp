#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int arr[1001];
bool attach[1001];

void tapeAttach(int index)
{
	for (int i = 0; i < L; i++)
	{
		if (index + i < 1001)
			attach[index + i] = true;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (attach[arr[i]] == true)
			continue;
		tapeAttach(arr[i]);
		answer++;
	}
	cout << answer << '\n';
	return 0;
}