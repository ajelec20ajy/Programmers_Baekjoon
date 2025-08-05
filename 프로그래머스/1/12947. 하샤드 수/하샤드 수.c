#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {\
int temp = 0;
int y = x;
while (y > 0) {
    temp += (y % 10);
    y /= 10;
}
bool answer = true;
if (x % temp) answer = false;
   
    return answer;
}

// 118 ->   118 % 10 = 8, x= x/10 = 18
//          11 % 10 = 1, x = x/10 = 1
//          1 % 10 = 1, x = x/10 = 0..