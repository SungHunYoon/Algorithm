#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int v;
vector<vector<pair<int, int>>> arr(100001);
bool visit[100001];
int maxNode;
int maxDis;

void dfs(int index, int dis)
{
    visit[index] = true;
    for (int i = 0; i < arr[index].size(); i++)
    {
        if (!visit[arr[index][i].first])
            dfs(arr[index][i].first, arr[index][i].second + dis);
    }
    if (maxDis < dis)
    {
        maxDis = dis;
        maxNode = index;
    }
    visit[index] = false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v;
    for (int i = 0; i < v; i++)
    {
        int index;
        cin >> index;
        int connect = 0, dis;
        while (connect != -1)
        {
            cin >> connect;
            if (connect != -1)
            {
                cin >> dis;
                arr[index].push_back({connect, dis});
            }
        }
    }
    dfs(1, 0);
    dfs(maxNode, 0);
    cout << maxDis << '\n';
    return (0);
}