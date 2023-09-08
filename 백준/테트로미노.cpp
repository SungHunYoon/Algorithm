#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[501][501];

int s1_x[4][4] = { {0, 1, 2, 3}, {-3, -2, -1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
int s1_y[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {-3, -2, -1, 0}, {3, 2, 1, 0} };

int s2_x[4][4] = { {0, 1, 0, 1}, {0, -1, 0, -1}, {0, 1, 0, 1}, {0, -1, 0, -1} };
int s2_y[4][4] = { {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, -1, -1}, {0, 0, -1, -1} };

int s3_x[8][4] = { {0, 0, 0, 1}, {0, 0, 0, -1}, {0, 0, 0, 1}, {0, 0, 0, -1},
                    {0, 1, 2, 2}, {0, -1, -2, -2}, {0, 1, 2, 2}, {0, -1, -2, 2} };
int s3_y[8][4] = { {0, 1, 2, 2}, {0, 1, 2, 2}, {0, -1, -2, -2}, {0, -1, -2, -2},
                    {0, 0, 0, -1}, {0, 0, 0, -1}, {0, 0, 0, 1}, {0, 0, 0, 1} };

int s4_x[8][4] = { {0, 0, 1, 1}, {0, 0, -1, -1}, {0, 0, 1, 1}, {0, 0, -1, -1},
                    {0, -1, -1, -2}, {0, 1, 1, 2}, {0, 1, 1, 2}, {0, -1, -1, -2} };
int s4_y[8][4] = { {0, 1, 1, 2}, {0, 1, 1, 2}, {0, -1, -1, -2}, {0, -1, -1, 2},
                    {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, -1, -1}, {0, 0, -1, -1} };

int s5_x[8][4] = { {0, 1, 1, 2}, {0, -1, -1, -2}, {0, 1, 1, 2}, {0, -1, -1, -2},
                    {0, 0, 1, 0}, {0, 0, -1, 0}, {0, 0, 1, 0}, {0, 0, -1, 0} };
int s5_y[8][4] = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, -1, 0}, {0, 0, -1, 0},
                    {0, 1, 1, 2}, {0, 1, 1, 2}, {0, -1, -1, -2}, {0, -1, -1, -2} };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            for (int k = 0; k < 4; k++)
            {
                int dx1, dx2, dx3, dx4;
                int dy1, dy2, dy3, dy4;
    
                dx1 = j + s1_x[k][0]; dy1 = i + s1_y[k][0];
                dx2 = j + s1_x[k][1]; dy2 = i + s1_y[k][1];
                dx3 = j + s1_x[k][2]; dy3 = i + s1_y[k][2];
                dx4 = j + s1_x[k][3]; dy4 = i + s1_y[k][3];
                if (0 <= dx1 && dx1 < m && 0 <= dy1 && dy1 < n &&
                    0 <= dx2 && dx2 < m && 0 <= dy2 && dy2 < n &&
                    0 <= dx3 && dx3 < m && 0 <= dy3 && dy3 < n &&
                    0 <= dx4 && dx4 < m && 0 <= dy4 && dy4 < n)
                {
                    tmp = arr[dy1][dx1];
                    tmp += arr[dy2][dx2];
                    tmp += arr[dy3][dx3];
                    tmp += arr[dy4][dx4];
                    if (tmp > answer)
                        answer = tmp;
                }
            }

            for (int k = 0; k < 4; k++)
            {
                int dx1, dx2, dx3, dx4;
                int dy1, dy2, dy3, dy4;
    
                dx1 = j + s2_x[k][0]; dy1 = i + s2_y[k][0];
                dx2 = j + s2_x[k][1]; dy2 = i + s2_y[k][1];
                dx3 = j + s2_x[k][2]; dy3 = i + s2_y[k][2];
                dx4 = j + s2_x[k][3]; dy4 = i + s2_y[k][3];
                if (0 <= dx1 && dx1 < m && 0 <= dy1 && dy1 < n &&
                    0 <= dx2 && dx2 < m && 0 <= dy2 && dy2 < n &&
                    0 <= dx3 && dx3 < m && 0 <= dy3 && dy3 < n &&
                    0 <= dx4 && dx4 < m && 0 <= dy4 && dy4 < n)
                {
                    tmp = arr[dy1][dx1];
                    tmp += arr[dy2][dx2];
                    tmp += arr[dy3][dx3];
                    tmp += arr[dy4][dx4];
                    if (tmp > answer)
                        answer = tmp;
                }
            }

            for (int k = 0; k < 8; k++)
            {
                int dx1, dx2, dx3, dx4;
                int dy1, dy2, dy3, dy4;
    
                dx1 = j + s3_x[k][0]; dy1 = i + s3_y[k][0];
                dx2 = j + s3_x[k][1]; dy2 = i + s3_y[k][1];
                dx3 = j + s3_x[k][2]; dy3 = i + s3_y[k][2];
                dx4 = j + s3_x[k][3]; dy4 = i + s3_y[k][3];
                if (0 <= dx1 && dx1 < m && 0 <= dy1 && dy1 < n &&
                    0 <= dx2 && dx2 < m && 0 <= dy2 && dy2 < n &&
                    0 <= dx3 && dx3 < m && 0 <= dy3 && dy3 < n &&
                    0 <= dx4 && dx4 < m && 0 <= dy4 && dy4 < n)
                {
                    tmp = arr[dy1][dx1];
                    tmp += arr[dy2][dx2];
                    tmp += arr[dy3][dx3];
                    tmp += arr[dy4][dx4];
                    if (tmp > answer)
                        answer = tmp;
                }
            }

            for (int k = 0; k < 8; k++)
            {
                int dx1, dx2, dx3, dx4;
                int dy1, dy2, dy3, dy4;
    
                dx1 = j + s4_x[k][0]; dy1 = i + s4_y[k][0];
                dx2 = j + s4_x[k][1]; dy2 = i + s4_y[k][1];
                dx3 = j + s4_x[k][2]; dy3 = i + s4_y[k][2];
                dx4 = j + s4_x[k][3]; dy4 = i + s4_y[k][3];
                if (0 <= dx1 && dx1 < m && 0 <= dy1 && dy1 < n &&
                    0 <= dx2 && dx2 < m && 0 <= dy2 && dy2 < n &&
                    0 <= dx3 && dx3 < m && 0 <= dy3 && dy3 < n &&
                    0 <= dx4 && dx4 < m && 0 <= dy4 && dy4 < n)
                {
                    tmp = arr[dy1][dx1];
                    tmp += arr[dy2][dx2];
                    tmp += arr[dy3][dx3];
                    tmp += arr[dy4][dx4];
                    if (tmp > answer)
                        answer = tmp;
                }
            }

            for (int k = 0; k < 8; k++)
            {
                int dx1, dx2, dx3, dx4;
                int dy1, dy2, dy3, dy4;
    
                dx1 = j + s5_x[k][0]; dy1 = i + s5_y[k][0];
                dx2 = j + s5_x[k][1]; dy2 = i + s5_y[k][1];
                dx3 = j + s5_x[k][2]; dy3 = i + s5_y[k][2];
                dx4 = j + s5_x[k][3]; dy4 = i + s5_y[k][3];
                if (0 <= dx1 && dx1 < m && 0 <= dy1 && dy1 < n &&
                    0 <= dx2 && dx2 < m && 0 <= dy2 && dy2 < n &&
                    0 <= dx3 && dx3 < m && 0 <= dy3 && dy3 < n &&
                    0 <= dx4 && dx4 < m && 0 <= dy4 && dy4 < n)
                {
                    tmp = arr[dy1][dx1];
                    tmp += arr[dy2][dx2];
                    tmp += arr[dy3][dx3];
                    tmp += arr[dy4][dx4];
                    if (tmp > answer)
                        answer = tmp;
                }
            }
        }
    }
    cout << answer << '\n';
    return (0);
}