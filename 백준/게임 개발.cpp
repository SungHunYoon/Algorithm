#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[501];
vector<int> v[501];
int inDegree[501];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        int num;
        while (cin >> num)
        {
            if (num == -1)
                break;
            v[num].push_back(i);
            inDegree[i]++;
        }
    }
    queue<int> q;
    int answer[501] = { 0, };
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            answer[i] = arr[i];
        }
    }
    int result[501];
    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
            break;
        int x = q.front();
        q.pop();
        result[i] = x;
        for (int j = 0; j < v[x].size(); j++)
        {
            int y = v[x][j];
            if (--inDegree[y] == 0)
                q.push(y);
            answer[y] = max(answer[y], answer[x] + arr[y]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << answer[i] << '\n';
    return (0);
}