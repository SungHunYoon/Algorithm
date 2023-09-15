#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(-num);
    }
    int answer = 0;
    while (pq.size() != 1)
    {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        answer += a + b;
        pq.push(-(a + b));
    }
    cout << answer << '\n';
    return (0);
}