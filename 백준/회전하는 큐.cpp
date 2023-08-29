#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    deque<int> dq;
    
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
        dq.push_back(i + 1);
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        int index;
        cin >> index;
        int j;
        for (j = 0; j < dq.size(); j++)
        {
            if (dq[j] == index)
                break;
        }
        if (j != 0)
        {
            int left = dq.size() - j;
            int right = j;
            if (right >= left)
            {
                for (int k = 0; k < left; k++)
                {
                    int tmp = dq.back();
                    dq.pop_back();
                    dq.push_front(tmp);
                }
                answer += left;
            }
            else
            {
                for (int k = 0; k < right; k++)
                {
                    int tmp = dq.front();
                    dq.pop_front();
                    dq.push_back(tmp);
                }
                answer += right;
            }
        }
        dq.pop_front();
    }
    cout << answer << '\n';
    return (0);
}