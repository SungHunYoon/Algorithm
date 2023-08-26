#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
    int n;
    vector<string> arr;

    cin >> n;
    arr.assign(n, "");
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<string> answer;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < arr[i].length(); j++)
        {
            string temp;
            
            temp = arr[i].substr(j);
            temp += arr[i].substr(0, j);

            if (answer.find(temp) != answer.end())
                break;
        }
        if (j == arr[i].length())
            answer.insert(arr[i]);
    }
    cout << answer.size() << endl;
    return (0);
}