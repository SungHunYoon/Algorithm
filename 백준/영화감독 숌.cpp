#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string s = "0";
    for (int i = 0; i < n; i++)
    {
        int j = stoi(s) + 1;
        s = to_string(j);
        while (s.find("666") == string::npos)
        {
            j = stoi(s) + 1;
            s = to_string(j);
        }
    }
    cout << s << '\n';
    return (0);
}