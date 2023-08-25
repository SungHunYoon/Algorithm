#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    int m;
    vector<int> a;
    vector<int> b;

    cin >> n;
    cin >> m;
    a.assign(n, 0);
    b.assign(m, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    vector<int> table (100000001, 0);
    int answer = 0;
    for (int i = 0; i < n; i++)
        table[a[i]] = 1;
    for (int i = 0; i < m; i++)
    {
        if (table[b[i]] == 1)
            answer++;
    }
    answer = a.size() + b.size() - (2 * answer);
    cout << answer << endl;
    return (0);
}