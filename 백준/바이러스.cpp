#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &v, int index)
{
    if (v[index] == index)
        return (index);
    v[index] = find(v, v[index]);
    return (v[index]);
}

void makeUnion(vector<int> &v, int a, int b)
{
    a = find(v, a);
    b = find(v, b);

    if (a == b)
        return;

    if (a < b)
        v[b] = a;
    else
        v[a] = b;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        v[i] = i;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        makeUnion(v, a, b);
    }
    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        if (1 == find(v, i))
            answer++;
    }
    cout << answer << '\n';
    return (0);
}