#include <iostream>

using namespace std;

int N;
long long len[100000];
long long arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> len[i];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	long long answer = arr[0] * len[0];
	long long top = arr[0];
	long long tmp = 0;
	for (int i = 1; i < N - 1; i++)
	{
		if (top > arr[i])
		{
			answer += tmp;
			top = arr[i];
			tmp = 0;
		}
		tmp += top * len[i];
		//cout << top << " " << tmp << '\n';
	}
	cout << answer + tmp << '\n';
	return 0;
}