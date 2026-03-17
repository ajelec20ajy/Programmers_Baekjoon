#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef struct key {
    int x, y;
    char alphabet;
}key;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Whai is simulation : 로직 옮기기
    // 상태(위치, 방향, 속도) - 규칙(종료, 예외) - 시간 흐름을 고려해서 상황을 코드 상으로 재현하는 것
    // 독수리 타법 : 왼손 검지 -> 자음
    //               오른손 검지 -> 모음
    // (x1, y1) -> (x2,y2)로 이동할 때, |x1-x2| + |y1-y2| 만큼의 시간이 걸린다.
    // 키 누르면 시간 1 소요

    // 상태란 현 위치입니다. pari <int, int> now;
    // 그래프를 만들어야 합니까?
    // 아니 그러면 알파벳별로 다 좌표를 일단 넣어놔야겠넴?

    char sl, sr;
    cin >> sl >> sr;
    
    int lx, ly;
    int rx, ry;
    int total_time = 0;
    switch (sl) {
        case 'q':
            ly = 0;
            lx = 0;
            break;
        case 'w':
            ly = 0;
            lx = 1;
            break;
        case 'e':
            ly = 0;
            lx = 2;
            break;
        case 'r':
            ly = 0;
            lx = 3;
            break;
        case 't':
            ly = 0;
            lx = 4;
            break;
        case 'y':
            ry = 0;
            rx = 5;
            break;
        case 'u':
            ry = 0;
            rx = 6;
            break;
        case 'i':
            ry = 0;
            rx = 7;
            break;
        case 'o':
            ry = 0;
            rx = 8;
            break;
        case 'p':
            ry = 0;
            rx = 9;
            break;
        case 'a':
            ly = 1;
            lx = 0;
            break;
        case 's':
            ly = 1;
            lx = 1;
            break;
        case 'd':
            ly = 1;
            lx = 2;
            break;
        case 'f':
            ly = 1;
            lx = 3;
            break;
        case 'g':
            ly = 1;
            lx = 4;
            break;
        case 'h':
            ry = 1;
            rx = 5;
            break;
        case 'j':
            ry = 1;
            rx = 6;
            break;
        case 'k':
            ry = 1;
            rx = 7;
            break;
        case 'l':
            ry = 1;
            rx = 8;
            break;
        case 'z':
            ly = 2;
            lx = 0;
            break;
        case 'x':
            ly = 2;
            lx = 1;
            break;
        case 'c':
            ly = 2;
            lx = 2;
            break;
        case 'v':
            ly = 2;
            lx = 3;
            break;
        case 'b':
            ry = 2;
            rx = 4;
            break;
        case 'n':
            ry = 2;
            rx = 5;
            break;
        case 'm':
            ry = 2;
            rx = 6;
            break;
        default:
            break;
        }
    switch (sr) {
        case 'q':
            ly = 0;
            lx = 0;
            break;
        case 'w':
            ly = 0;
            lx = 1;
            break;
        case 'e':
            ly = 0;
            lx = 2;
            break;
        case 'r':
            ly = 0;
            lx = 3;
            break;
        case 't':
            ly = 0;
            lx = 4;
            break;
        case 'y':
            ry = 0;
            rx = 5;
            break;
        case 'u':
            ry = 0;
            rx = 6;
            break;
        case 'i':
            ry = 0;
            rx = 7;
            break;
        case 'o':
            ry = 0;
            rx = 8;
            break;
        case 'p':
            ry = 0;
            rx = 9;
            break;
        case 'a':
            ly = 1;
            lx = 0;
            break;
        case 's':
            ly = 1;
            lx = 1;
            break;
        case 'd':
            ly = 1;
            lx = 2;
            break;
        case 'f':
            ly = 1;
            lx = 3;
            break;
        case 'g':
            ly = 1;
            lx = 4;
            break;
        case 'h':
            ry = 1;
            rx = 5;
            break;
        case 'j':
            ry = 1;
            rx = 6;
            break;
        case 'k':
            ry = 1;
            rx = 7;
            break;
        case 'l':
            ry = 1;
            rx = 8;
            break;
        case 'z':
            ly = 2;
            lx = 0;
            break;
        case 'x':
            ly = 2;
            lx = 1;
            break;
        case 'c':
            ly = 2;
            lx = 2;
            break;
        case 'v':
            ly = 2;
            lx = 3;
            break;
        case 'b':
            ry = 2;
            rx = 4;
            break;
        case 'n':
            ry = 2;
            rx = 5;
            break;
        case 'm':
            ry = 2;
            rx = 6;
            break;
        default:
            break;
        }

    string str;
    cin >> str;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        char tmp = str[i];
        int ny, nx;
        bool isRight = false;
        int time;
        switch (tmp) {
        case 'q':
            ny = 0;
            nx = 0;
            break;
        case 'w':
            ny = 0;
            nx = 1;
            break;
        case 'e':
            ny = 0;
            nx = 2;
            break;
        case 'r':
            ny = 0;
            nx = 3;
            break;
        case 't':
            ny = 0;
            nx = 4;
            break;
        case 'y':
            ny = 0;
            nx = 5;
            isRight = true;
            break;
        case 'u':
            ny = 0;
            nx = 6;
            isRight = true;
            break;
        case 'i':
            ny = 0;
            nx = 7;
            isRight = true;
            break;
        case 'o':
            ny = 0;
            nx = 8;
            isRight = true;
            break;
        case 'p':
            ny = 0;
            nx = 9;
            isRight = true;
            break;
        case 'a':
            ny = 1;
            nx = 0;
            break;
        case 's':
            ny = 1;
            nx = 1;
            break;
        case 'd':
            ny = 1;
            nx = 2;
            break;
        case 'f':
            ny = 1;
            nx = 3;
            break;
        case 'g':
            ny = 1;
            nx = 4;
            break;
        case 'h':
            ny = 1;
            nx = 5;
            isRight = true;
            break;
        case 'j':
            ny = 1;
            nx = 6;
            isRight = true;
            break;
        case 'k':
            ny = 1;
            nx = 7;
            isRight = true;
            break;
        case 'l':
            ny = 1;
            nx = 8;
            isRight = true;
            break;
        case 'z':
            ny = 2;
            nx = 0;
            break;
        case 'x':
            ny = 2;
            nx = 1;
            break;
        case 'c':
            ny = 2;
            nx = 2;
            break;
        case 'v':
            ny = 2;
            nx = 3;
            break;
        case 'b':
            ny = 2;
            nx = 4;
            isRight = true;
            break;
        case 'n':
            ny = 2;
            nx = 5;
            isRight = true;
            break;
        case 'm':
            ny = 2;
            nx = 6;
            isRight = true;
            break;
        default:
            break;
        }
        if (isRight) { // sr 조작
            time = 1 + abs((nx - rx)) + abs((ny - ry));
            rx = nx;
            ry = ny;
        }
        else {
            time = 1 + abs((nx - lx)) + abs((ny - ly));
            lx = nx;
            ly = ny;
        }
        total_time += time;
    }
    
    cout << total_time;

    return 0;
}