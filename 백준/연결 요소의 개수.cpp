#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[1001];

int find(int i)
{
    if (arr[i] == i)
        return (i);
    arr[i] = find(arr[i]);
    return (arr[i]);
}

void makeUnion(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;
    if (a > b)
        arr[a] = b;
    else
        arr[b] = a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        makeUnion(a, b);
    }
    int answer = 0;
    bool check[1001] = { false, };
    for (int i = 1; i <= n; i++)
    {
        if (!check[find(arr[i])])
        {
            answer++;
            check[find(arr[i])] = true;
        }
    }
    cout << answer << '\n';
    return (0);
}