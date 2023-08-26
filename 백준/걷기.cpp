#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int x;
    int y;
    int w;
    int s;

    cin >> x;
    cin >> y;
    cin >> w;
    cin >> s;

    long long answer = 0;
    if (2 * w <= s)
        answer = (x + y) * w;
    else
    {
        int cx = 0;
        int cy = 0;

        while (cx != x || cy != y)
        {
            long long move;

            if (cx < x && cy < y)
            {
                if (x - cx > y - cy)
                    move = y - cy;
                else
                    move = x - cx;
                cx += move;
                cy += move;
                move *= s;
            }
            else if (cx == x)
            {
                move = y - cy;
                cy += move;
                if (s >= w)
                    move *= w;
                else
                {
                    if (move % 2 != 0)
                        move = w + (move - 1) * s;
                    else
                        move *= s;
                }
            }
            else
            {
                move = x - cx;
                cx += move;
                if (s >= w)
                    move *= w;
                else
                {
                    if (move % 2 != 0)
                        move = w + (move - 1) * s;
                    else
                        move *= s;
                }
            }
            answer += move;
        }
    }
    cout << answer << endl;
    return (0);
}