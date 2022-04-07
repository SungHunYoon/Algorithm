#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for( int i = 0; i < n; i++ )
    {
        string buffer;
        for( int j = 0; j < n; j++ )
        {
            if( ( arr1[ i ] >> n - j - 1 & 0x01 ) || ( arr2[ i ] >> n - j - 1 & 0x01 ) )
                buffer += '#';
            else
                buffer += ' ';
        }
        answer.push_back( buffer );
    }
    return answer;
}