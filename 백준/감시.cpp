#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[9][9];
int answer = 1000000000;

void recursive(int x, int y, int index)
{
    if (x == m)
    {
        x = 0;
        y++;
    }
    if (y == n)
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                    tmp++;
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        answer = min(answer, tmp);
        return;
    }

    if (arr[y][x] == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
            }
            else if (i == 1)
            {
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
            }
            else if (i == 2)
            {
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
            }
            else
            {
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
            }
        }
    }
    else if (arr[y][x] == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
            }
            else
            {
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;                    
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;                    
                }                
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
            }
        }
    }
    else if (arr[y][x] == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
            }
            else if (i == 1)
            {
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
            }
            else if (i == 2)
            {
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
            }
            else
            {
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
            }
        }
    }
    else if (arr[y][x] == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
            }
            else if (i == 1)
            {
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] == index;
                    else if (arr[y][j] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == index)
                        arr[y][j] == 0;
                    else if (arr[y][j] == 6)
                        break;
                }
            }
            else if (i == 2)
            {
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;                    
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;                    
                }
                for (int j = x + 1; j < m; j++)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
            }
            else
            {
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;                    
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == 0)
                        arr[j][x] = index;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == 0)
                        arr[y][j] = index;
                    else if (arr[y][j] == 6)
                        break;
                }
                recursive(x + 1, y, index + 1);
                for (int j = y - 1; j >= 0; j--)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;                    
                }
                for (int j = y + 1; j < n; j++)
                {
                    if (arr[j][x] == index)
                        arr[j][x] = 0;
                    else if (arr[j][x] == 6)
                        break;
                }
                for (int j = x - 1; j >= 0; j--)
                {
                    if (arr[y][j] == index)
                        arr[y][j] = 0;
                    else if (arr[y][j] == 6)
                        break;
                }
            }
        }
    }
    else if (arr[y][x] == 5)
    {
        for (int i = y - 1; i >= 0; i--)
        {
            if (arr[i][x] == 0)
                arr[i][x] = index;
            else if (arr[i][x] == 6)
                break;
        }
        for (int i = y + 1; i < n; i++)
        {
            if (arr[i][x] == 0)
                arr[i][x] = index;
            else if (arr[i][x] == 6)
                break;
        }
        for (int i = x - 1; i >= 0; i--)
        {
            if (arr[y][i] == 0)
                arr[y][i] = index;
            else if (arr[y][i] == 6)
                break;            
        }
        for (int i = x + 1; i < m; i++)
        {
            if (arr[y][i] == 0)
                arr[y][i] = index;
            else if (arr[y][i] == 6)
                break;
        }
        recursive(x + 1, y, index + 1);
        for (int i = y - 1; i >= 0; i--)
        {
            if (arr[i][x] == index)
                arr[i][x] = 0;
            else if (arr[i][x] == 6)
                break;            
        }
        for (int i = y + 1; i < n; i++)
        {
            if (arr[i][x] == index)
                arr[i][x] = 0;
            else if (arr[i][x] == 6)
                break;
        }
        for (int i = x - 1; i >= 0; i--)
        {
            if (arr[y][i] == index)
                arr[y][i] = 0;
            else if (arr[y][i] == 6)
                break;            
        }
        for (int i = x + 1; i < m; i++)
        {
            if (arr[y][i] == index)
                arr[y][i] = 0;
            else if (arr[y][i] == 6)
                break;
        }
    }
    else
        recursive(x + 1, y, index + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    recursive(0, 0, 10);
    cout << answer << '\n';
    return (0);
}