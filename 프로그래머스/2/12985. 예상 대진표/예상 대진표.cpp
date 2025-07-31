#include <iostream>
#include <math.h>
using namespace std;

int solution(int n, int a, int b)
{
    int x =  log(n) / log(2);
    for(int answer = 0; answer<=x; answer++){
        a=(a+1)/2; b=(b+1)/2;
        if(a==b) {return (answer+1);}
    }
}
/* n=8, a=4, b=7
[1] 2, 4 
[2] 1 2
[3]
*/