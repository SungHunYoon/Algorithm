#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> dq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (dq.empty())
			dq.push_back(i + 1);
		else
			dq.insert(dq.begin() + dq.size() - tmp, i + 1);
		//cout << dq.size() << '\n';
	}
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << ' ';
	cout << '\n';
	return 0;
}