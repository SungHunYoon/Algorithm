#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    int m;

    cin >> n;
    cin >> m;

    int top = m - 1, bottom = 0, left = 0, right = n - 1;
    int dir = 0;
    int x = 0, y = 0;

    while (right - left >= 0 && top - bottom >= 0)
    {
        if (dir == 0)
        {
            x = right;
            y = bottom;
            bottom++;
        }
        else if (dir == 1)
        {
            x = right;
            y = top;
            right--;
        }
        else if (dir == 2)
        {
            x = left;
            y = top;
            top--;
        }
        else
        {
            x = left;
            y = bottom;
            left++;
        }
        dir++;
        if (dir >= 4)
            dir = 0;
    }
    cout << x << " " << y << endl;
    return (0);
}