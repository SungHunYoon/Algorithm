#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<pair<int, int>> s;
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (!s.empty() && s.top().first < arr[i])
        {
            answer += s.top().second;
            s.pop();
        }

        if (!s.empty())
        {
            if (s.top().first == arr[i])
            {
                answer += s.top().second;
                cnt = s.top().second + 1;
                s.pop();
                if (!s.empty())
                    answer++;
            }
            else
                answer++;
        }
        s.push({arr[i], cnt});
    }
    cout << answer << '\n';
    return (0);
}