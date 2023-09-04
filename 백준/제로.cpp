#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    stack<int> stk;
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        if (num == 0)
            stk.pop();
        else
            stk.push(num);
    }
    int answer = 0;
    while (!stk.empty())
    {
        answer += stk.top();
        stk.pop();
    }
    cout << answer << '\n';
    return (0);
}