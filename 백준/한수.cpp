#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    int n;
    int t;
    int answer;

    cin >> n;
    answer = 0;
    for (int i = 1; i <= n; i++)
    {
        t = i;
        deque<int> s;
        while (t > 0)
        {
            s.push_front(t % 10);
            t /= 10;
        }
        if (s.size() == 1)
            answer++;
        else
        {
            int interval;
            int j;
            for (j = 0; j < s.size() - 1; j++)
            {
                if (j == 0)
                    interval = s[j + 1] - s[j];
                if (s[j + 1] - s[j] != interval)
                    break;
            }
            if (j + 1 == s.size())
                answer++;
        }
    }
    cout << answer << endl;
    return (0);
}