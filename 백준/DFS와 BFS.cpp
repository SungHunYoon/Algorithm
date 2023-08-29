#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dfs(vector<vector<int>> &arr, vector<int> &answer, vector<bool> &visit, int index)
{
    int ret = 0;
    for (int i = 0; i < arr[index].size(); i++)
    {
        if (!visit[arr[index][i]])
        {
            visit[arr[index][i]] = true;
            answer.push_back(arr[index][i]);
            dfs(arr, answer, visit, arr[index][i]);
        }
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> arr (n + 1);
    for (int i = 0; i < m; i++)
    {
        int index, obj;
        cin >> index >> obj;
        arr[index].push_back(obj);
        arr[obj].push_back(index);
    }
    for (int i = 1; i < n + 1; i++)
        sort(arr[i].begin(), arr[i].end());
    
    vector<int> answer1;
    vector<bool> visit1 (n + 1, false);
    answer1.push_back(v);
    visit1[v] = true;
    dfs(arr, answer1, visit1, v);
    for (int i = 0; i < answer1.size(); i++)
    {
        cout << answer1[i];
        if (i + 1 < answer1.size())
            cout << ' ';
    }
    cout << '\n';
    
    vector<int> answer;
    vector<bool> visit (n + 1, false);
    queue<int> q;
    q.push(v);
    visit[v] = true;
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        answer.push_back(index);
        for (int i = 0; i < arr[index].size(); i++)
        {
            if (!visit[arr[index][i]])
            {
                visit[arr[index][i]] = true;
                q.push(arr[index][i]);
            }
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i + 1 < answer.size())
            cout << ' ';
    }
    cout << '\n';
    return (0);
}