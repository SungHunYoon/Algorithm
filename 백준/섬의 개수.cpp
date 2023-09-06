#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void recursive(vector<vector<int>> &arr, int h, int w, int x, int y, int cnt)
{
    if (x < 0 || x >= w || y < 0 || y >= h)
        return ;
    else if (arr[y][x] != 1)
        return ;
    arr[y][x] += cnt + 1;
    recursive(arr, h, w, x - 1, y + 1, cnt);
    recursive(arr, h, w, x, y + 1, cnt);
    recursive(arr, h, w, x + 1, y + 1, cnt);
    recursive(arr, h, w, x - 1, y, cnt);
    recursive(arr, h, w, x + 1, y, cnt);
    recursive(arr, h, w, x - 1, y - 1, cnt);
    recursive(arr, h, w, x, y - 1, cnt);
    recursive(arr, h, w, x + 1, y - 1, cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w, h;
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;
        vector<vector<int>> arr(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> arr[i][j];

        int cnt = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (arr[i][j] == 1)
                {
                    recursive(arr, h, w, j, i, cnt);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return (0);
}