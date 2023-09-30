#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, d;
vector<int> node[100001];
bool visit[100001];
int leaf[100001];
int answer;

int dfs(int index)
{
    int ret = 0;

    for(int i = 0; i < node[index].size(); i++)
    {
        if (!visit[node[index][i]])
        {
            visit[node[index][i]] = true;
            ret = max(ret, dfs(node[index][i]) + 1);
        }
    }
    leaf[index] = ret;
    return (ret);
}

void dfs1(int index)
{
    for (int i = 0; i < node[index].size(); i++)
    {
        if (!visit[node[index][i]])
        {
            visit[node[index][i]] = true;
            if (leaf[node[index][i]] >= d)
                answer++;
            dfs1(node[index][i]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s >> d;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    visit[s] = true;
    dfs(s);
    for (int i = 0; i < n; i++)
        visit[i] = false;
    visit[s] = true;
    dfs1(s);
    cout << answer * 2 << '\n';
    return (0);
}