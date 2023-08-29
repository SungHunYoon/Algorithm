#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int left_check(vector<pair<int, int>> arr, int n)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].first > arr[n].first)
            cnt++;
    }
    return (cnt);
}

int recursive(vector<pair<int, int>> &arr, vector<pair<int, int>> &answer, vector<bool> &visit, int index)
{
    if (index >= arr.size())
        return (1);
    int ret = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        answer.push_back(arr[i]);
        if (!visit[i] && left_check(answer, index) == answer[index].second)
        {
            visit[i] = true;
            ret = recursive(arr, answer, visit, index + 1);
            if (ret > 0)
                return (ret);
            visit[i] = false;
        }
        answer.erase(answer.begin() + index);
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back({i + 1, t});
    }
    vector<bool> visit (n, false);
    vector<pair<int, int>> answer;
    recursive(arr, answer, visit, 0);
    for (int i = 0; i < n; i++)
    {
        cout << answer[i].first;
        if (i + 1 < n)
            cout << ' ';
    }
    cout << '\n';
    return (0);
}