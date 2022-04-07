#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc( int a, int b )
{
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> temp;
    
    while( n != 0 )
    {
        temp.push_back( n % 10 );
        n /= 10;
    }
    
    sort( temp.begin(), temp.end(), desc );
    
    int i = 1;
    while( !temp.empty() )
    {
        answer += temp.back() * i;
        i *= 10;
        temp.pop_back();
    }
    
    return answer;
}