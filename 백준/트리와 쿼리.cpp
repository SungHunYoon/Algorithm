#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int make_tree(vector<vector<int>> &g, vector<int> &answer, vector<bool> &v, int index)
{
    int ret = 0;
    v[index] = true;
    for (int i = 0; i < g[index].size(); i++)
    {
        if (!v[g[index][i]])
            ret += make_tree(g, answer, v, g[index][i]);
    }
    answer[index] = ret + 1;
    return (answer[index]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;
    vector<vector<int>> g(n + 1);
    vector<int> answer(n + 1, 0);
    vector<bool> v(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    make_tree(g, answer, v, r);
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        cout << answer[a] << '\n';
    }
    return (0);
}