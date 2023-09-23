#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct s_shark
{
    int r, c, s, d, z;
    int index;
} t_shark;

int r, c, m;
t_shark shark[10001];
vector<int> arr[101][101];

int fishing(int c)
{
    for (int i = 1; i <= r; i++)
    {
        if (arr[i][c].size() != 0)
        {
            int size = shark[arr[i][c][0]].z;
            arr[i][c].erase(arr[i][c].begin());
            return (size);
        }
    }
    return (0);
}

void move(int index)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j].size() != 0 && shark[arr[i][j][0]].index != index)
            {
                if (shark[arr[i][j][0]].d == 1)
                {
                    int s = shark[arr[i][j][0]].s % ((r - 1) * 2);
                    for (int k = 0; k < s; k++)
                    {
                        if (shark[arr[i][j][0]].d == 1)
                        {
                            shark[arr[i][j][0]].r--;
                            if (shark[arr[i][j][0]].r < 1)
                            {
                                shark[arr[i][j][0]].r = 2;
                                shark[arr[i][j][0]].d = 2;
                            }
                        }
                        else
                        {
                            shark[arr[i][j][0]].r++;
                            if (shark[arr[i][j][0]].r > r)
                            {
                                shark[arr[i][j][0]].r = r - 1;
                                shark[arr[i][j][0]].d = 1;
                            }
                        }
                    }
                }
                else if (shark[arr[i][j][0]].d == 2)
                {
                    int s = shark[arr[i][j][0]].s % ((r - 1) * 2);
                    for (int k = 0; k < s; k++)
                    {
                        if (shark[arr[i][j][0]].d == 1)
                        {
                            shark[arr[i][j][0]].r--;
                            if (shark[arr[i][j][0]].r < 1)
                            {
                                shark[arr[i][j][0]].r = 2;
                                shark[arr[i][j][0]].d = 2;
                            }
                        }
                        else
                        {
                            shark[arr[i][j][0]].r++;
                            if (shark[arr[i][j][0]].r > r)
                            {
                                shark[arr[i][j][0]].r = r - 1;
                                shark[arr[i][j][0]].d = 1;
                            }
                        }
                    }
                }
                else if (shark[arr[i][j][0]].d == 3)
                {
                    int s = shark[arr[i][j][0]].s % ((c - 1) * 2);
                    for (int k = 0; k < s; k++)
                    {
                        if (shark[arr[i][j][0]].d == 4)
                        {
                            shark[arr[i][j][0]].c--;
                            if (shark[arr[i][j][0]].c < 1)
                            {
                                shark[arr[i][j][0]].c = 2;
                                shark[arr[i][j][0]].d = 3;
                            }
                        }
                        else
                        {
                            shark[arr[i][j][0]].c++;
                            if (shark[arr[i][j][0]].c > c)
                            {
                                shark[arr[i][j][0]].c = c - 1;
                                shark[arr[i][j][0]].d = 4;
                            }
                        }
                    }
                }
                else
                {
                    int s = shark[arr[i][j][0]].s % ((c - 1) * 2);
                    for (int k = 0; k < s; k++)
                    {
                        if (shark[arr[i][j][0]].d == 4)
                        {
                            shark[arr[i][j][0]].c--;
                            if (shark[arr[i][j][0]].c < 1)
                            {
                                shark[arr[i][j][0]].c = 2;
                                shark[arr[i][j][0]].d = 3;
                            }
                        }
                        else
                        {
                            shark[arr[i][j][0]].c++;
                            if (shark[arr[i][j][0]].c > c)
                            {
                                shark[arr[i][j][0]].c = c - 1;
                                shark[arr[i][j][0]].d = 4;
                            }
                        }
                    }
                }
                shark[arr[i][j][0]].index++;
                arr[shark[arr[i][j][0]].r][shark[arr[i][j][0]].c].push_back(arr[i][j][0]);
                arr[i][j].erase(arr[i][j].begin());
            }
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j].size() > 1)
            {
                int idx = 0;
                int maxSize = 0;
                for (int k = 0; k < arr[i][j].size(); k++)
                {
                    if (shark[arr[i][j][k]].z > maxSize)
                    {
                        maxSize = shark[arr[i][j][k]].z;
                        idx = arr[i][j][k];
                    }
                }
                arr[i][j].erase(arr[i][j].begin(), arr[i][j].end());
                arr[i][j].push_back(idx);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        arr[shark[i].r][shark[i].c].push_back(i);
    }
    
    int answer = 0;
    for (int i = 1; i <= c; i++)
    {
        int fish = fishing(i);
        if (fish != 0)
            answer += fish;
        move(i);
    }
    cout << answer << '\n';
    return (0);
}