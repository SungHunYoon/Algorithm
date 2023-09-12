#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int node[100001];
bool visit[100001];
vector<int> arr[100001];

void dfs(int index)
{
    visit[index] = true;
    for (int i = 0; i < arr[index].size(); i++)
    {
        if (!visit[arr[index][i]])
        {
            node[arr[index][i]] = index;
            dfs(arr[index][i]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            node[i] = i;
            dfs(i);
        }
    }
    for (int i = 2; i <= n; i++)
        cout << node[i] << '\n';
    return (0);
}