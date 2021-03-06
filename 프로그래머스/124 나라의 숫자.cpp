#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while( n != 0 )
    {
        switch( n % 3 )
        {
            case 0:
                answer = "4" + answer;
                n -= 1;
                break;
            case 1:
                answer = "1" + answer;
                break;
            case 2:
                answer = "2" + answer;
                break;
        }
        n /= 3;
    }
    
    return answer;
}