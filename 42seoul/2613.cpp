#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[301];
bool visit[30001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
    int s = 0, e = 0;
	for (int i = 0; i < N; i++)
    {
		cin >> arr[i];
        e += arr[i];
    }
    int minSum = 1e9;
    vector<int> answer;
    while (s <= e)
    {
        if (visit[e])
            break;
        visit[e] = true;
        int sum = 0, cnt = 0, maxSum = 0;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            if (sum + arr[i] <= e)
            {
                sum += arr[i];
                cnt++;
            }
            else
            {
                if (maxSum < sum)
                    maxSum = sum;
                if (cnt != 0)
                    v.push_back(cnt);
                sum = arr[i];
                cnt = 1;
            }
        }
        if (cnt != 0)
        {
            if (maxSum < sum)
                maxSum = sum;
            v.push_back(cnt);
        }
        int mid = (s + e) / 2;
        if (M == v.size())
        {
            minSum = maxSum;
            answer = v;
            break;
        }
        else if (M > v.size())
            e = mid;
        else
            e++;
    }
    for (int i = e; i >= 0; i--)
    {
        int sum = 0, cnt = 0, maxSum = 0;
        vector<int> v;
        for (int j = 0; j < N; j++)
        {
            if (sum + arr[j] <= i)
            {
                sum += arr[j];
                cnt++;
            }
            else
            {
                if (maxSum < sum)
                    maxSum = sum;
                if (cnt != 0)
                    v.push_back(cnt);
                sum = arr[j];
                cnt = 1;
            }
        }
        if (cnt != 0)
        {
            if (maxSum < sum)
                maxSum = sum;
            v.push_back(cnt);
        }
        if (M < v.size())
            break;
        if (M == v.size() && minSum > maxSum)
        {
            minSum = maxSum;
            answer = v;
        }
    }
    if (answer.size() != M)
    {
        int maxSum = 0;
        int sum = 0, cnt = 0;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            if (sum + arr[i] <= e)
            {
                sum += arr[i];
                cnt++;
            }
            else
            {
                if (cnt != 0)
                    v.push_back(cnt);
                if (v.size() + (N - i - 1) < M)
                {
                    for (int j = i; j < N; j++)
                    {
                        if (maxSum < arr[j])
                            maxSum = arr[j];
                        v.push_back(1);
                    }
                    break;
                }
                if (maxSum < sum)
                    maxSum = sum;
                sum = arr[i];
                cnt = 1;
            }
        }
        cout << maxSum << '\n';
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << '\n';
    }
    else
    {
        cout << minSum << '\n';
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << ' ';
        cout << '\n';
    }
	return 0;
}