#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];
int trace[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> answer;
    answer.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        if (answer.back() < arr[i])
        {
            trace[i] = answer.size();
            answer.push_back(arr[i]);
        }
        else
        {
            auto it = lower_bound(answer.begin(), answer.end(), arr[i]);
            *it = arr[i];
            trace[i] = distance(answer.begin(), it);
        }
    }
    cout << answer.size() << '\n';
    int idx = answer.size() - 1;
    vector<int> p;
    for (int i = N - 1; i >= 0 && idx >= 0; i--)
    {
        if (trace[i] != idx)
            continue;
        p.push_back(arr[i]);
        idx--;
    }
    for (auto it = p.rbegin(); it != p.rend(); it++)
        cout << *it << ' ';
    cout << '\n';
    return 0;
}