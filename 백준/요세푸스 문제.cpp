#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    int k;
    vector<int> answer;

    cin >> n;
    cin >> k;
    vector<int> arr(n + 1);
    for (int i = 0; i < n + 1; i++)
        arr[i] = i;
    vector<int> tmp;
    int i = k;
    while (arr.size() > 1)
    {
        if (i < arr.size())
        {
            answer.push_back(arr[i]);
            tmp.push_back(i);
            i += k;
        }
        if (i > arr.size() - 1)
        {
            i -= arr.size() - 1;
            for (int j = tmp.size() - 1; j >= 0; j--)
            {
                vector<int>::iterator iter = arr.begin();
                iter += tmp[j];
                arr.erase(iter);
                tmp.pop_back();
            }
        }
    }
    cout << "<";
    for (vector<int>::iterator iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout << *iter;
        if (*iter != answer.at(answer.size() - 1))
            cout << ", ";
    }
    cout << ">" << endl;
    return (0);
}