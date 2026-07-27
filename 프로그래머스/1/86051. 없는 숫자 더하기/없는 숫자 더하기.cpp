#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int ans = 0;
    for(int i = 0; i <= 9; i++){
        bool flag = false;
        for(int n : numbers){
            if(n == i) flag = true;
        }
        if(!flag) ans += i;
    }
    return ans;
}