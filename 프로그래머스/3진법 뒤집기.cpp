#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> temp; 
    
    while( n != 0 )
    {
        int mod = n % 3;
        
        temp.push_back( mod );
        
        n /= 3;
    }
    
    int pow = 1;
    
    while( !temp.empty() )
    {
        answer += temp.back() * pow;
        temp.pop_back();
        pow *= 3;
    }
    
    return answer;
}