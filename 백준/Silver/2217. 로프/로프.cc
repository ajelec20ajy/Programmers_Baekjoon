#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) { // true면 a가 b보다 앞인게 맞아요. 아니면 뒤로 보내세용
    if (a < b) return true; // a<b면 true니깐 오름차순으로 감
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 가능한거 : 최소 중량 제한의 로프 * 지금 달려있는 로프 개수 = 최대 가능 중량
    // 일단 다 달아. 
    // 그리고 약한 로프들 하나씩 끊어버려
    // 갱신 조건 : Wmax < W면 갱신!
    int N; // 로프 수
    vector<int> rope;

    cin >> N; // 로프 개수 입력받기
    for (int i = 0; i < N; i++) { // 로프 정보 받기
        int temp; cin >> temp;
        rope.push_back(temp);
    }

    sort(rope.begin(), rope.end(), compare);
  
   
    int max = N * rope.front();

    for (int i = 0; i < N; i++) { // i = 자른 로프 갯수
        int total = (N-i) *rope[i]; // 하나 젤 약한거 짤라내고, 버틸 수 있는 최대
        // 위의 식에서 이미 rope[i](젤약한거)가 버틸 수 있는 최대 하중으로 들어가서 별도로 검사필요없
        if (total > max) { // 기존보다 더 많이 버티면
            max = total; // 업뎃
        }
    }
    
    cout << max;
    return 0;
}
// x+y vs x+y+z