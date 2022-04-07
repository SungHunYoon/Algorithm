using namespace std;

long long solution(int w,int h)
{
	long long answer = 1;
    
    answer = ( long long )w * ( long long )h;
    
    long long gcd;
    for( long long i = w < h ? w : h; i > 0; i-- )
    {
        if( w % i == 0 && h % i == 0 )
        {
            gcd = i;
            break;
        }
    }
    
    answer -= gcd * ( w / gcd + h / gcd - 1 );
    
	return answer;
}