#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp( string a, string b )
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str;
    
    for( auto num : numbers )
        str.push_back( to_string( num ) );
    
    sort( str.begin(), str.end(), cmp );
    
    for( auto num : str )
        answer += num;
    
    if( answer[ 0 ] == '0' ) answer = "0";
    
    return answer;
}