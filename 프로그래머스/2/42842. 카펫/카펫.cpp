#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 가로길이 m, 세로길이 n
    // 생각해봐라 갈색 테두리의 개수는? = 2*m + (n-2) * 2 = 2(m+n) - 4
    // 그럼 또 생각해봐라, 노란색의 개수는 ? = (m-2) * (n-2)
    // 그럼 방정식을 풀어보거라?
    // brown(const) = 2m + 2n - 4
    // yellow(const) = (m-2) * (n-2) = mn - (2m + 2n - 4) = mn - brown
    // mn = brown + yellow
    // 아 방정식 못세우게써 걍 탐색 ㄱ
    // m이 max일려면 n이 3이어야지 그럼 m_max = (brown -2) / 2
    int n;
    for(int m = 3; m <= 2499; m++){
        for(int n = 3; n <= 999999; n++){
            if((m-2)*(n-2) == yellow){
                if(2*m+2*n-4 == brown)
                    return {n,m};
            }
        }
    }
}