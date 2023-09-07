#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
char arr[101][101];
bool visit[101][101];

void recursive(int x, int y, char c)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return;
    else if (visit[y][x])
        return;
    else if (arr[y][x] != c)
        return;
    visit[y][x] = true;
    if (arr[y][x] == 'G')
        arr[y][x] = 'R';
    recursive(x + 1, y, c);
    recursive(x - 1, y, c);
    recursive(x, y + 1, c);
    recursive(x, y - 1, c);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int normal = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                normal++;
                recursive(j, i, arr[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visit[i][j] = false;
    int abnormal = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                abnormal++;
                recursive(j, i, arr[i][j]);
            }
        }
    }
    cout << normal << ' ' << abnormal << '\n';
    return (0);
}