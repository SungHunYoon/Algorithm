#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    int i = 0;
    while( i < arr.size() )
    {
        if( answer.empty() || answer.back() != arr[ i ] )
        {
            answer.push_back( arr[ i ] );
        }
        i++;
    }

    return answer;
}