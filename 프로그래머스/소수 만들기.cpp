#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num)
{
        for(int i=2; i*i<=num; i++)
        {
            if(num % i == 0) return false;
        }
        return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    
    for( int i = 0; i < nums.size(); i++ )
    {
        for( int j = i + 1; j < nums.size(); j++ )
        {
            for( int k = j + 1; k < nums.size(); k++ )
            {
                if( isPrime( nums[ i ] + nums[ j ] + nums[ k ] ) )
                {
                    answer += 1;
                }
            }
        }
    }

    return answer;
}