#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int contain_circle(vector<int> coordi, int x, int y, int w, int h, int dir)
{
    if (dir == 0)
    {
        //cout << "left : " << abs(sqrt(pow(coordi[0] - x, 2) + pow(coordi[1] - (y + (h / 2)), 2))) << endl;
        if (h / 2 >= abs(sqrt(pow(coordi[0] - x, 2) + pow(coordi[1] - (y + (h / 2)), 2))))
            return (1);
    }
    else
    {
        //cout << "right : " << abs(sqrt(pow(coordi[0] - (x + w), 2) + pow(coordi[1] - (y + (h / 2)), 2))) << endl;
        if (h / 2 >= abs(sqrt(pow(coordi[0] - (x + w), 2) + pow(coordi[1] - (y + (h / 2)), 2))))
            return (1);
    }
    return (0);
}

int contain_sqaure(vector<int> coordi, int x, int y, int w, int h)
{
    if (x <= coordi[0] && coordi[0] <= x + w && y <= coordi[1] && coordi[1] <= y + h)
        return (1);
    else
        return (0);
}

int main(void)
{
    int w;
    int h;
    int x;
    int y;
    int p;
    vector<vector<int>> arr;

    cin >> w;
    cin >> h;
    cin >> x;
    cin >> y;
    cin >> p;
    arr.assign(p, vector<int>(2, 0));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < 2; j++)
            cin >> arr[i][j];
    int answer = 0;
    for (int i = 0; i < p; i++)
    {
        int isContain = contain_circle(arr[i], x, y, w, h, 0);
        isContain += contain_circle(arr[i], x, y, w, h, 1);
        isContain += contain_sqaure(arr[i], x, y, w, h);
        if (isContain > 0)
            answer += 1;
    }
    cout << answer << endl;
    return (0);
}