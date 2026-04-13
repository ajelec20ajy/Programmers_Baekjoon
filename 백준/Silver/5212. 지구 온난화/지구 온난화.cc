#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    인접 네 칸 중, 3칸 이상이 바다면은 그 땅은 잠깁니다(상하좌우가 인접)
    */

    int R, C;
    cin >> R >> C;

    vector<vector<char>> map(R, vector<char>(C));
    

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }
    }

    vector<vector<char>> next_map = map;

    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char cur = map[i][j];
            if (cur == '.') continue;
            cnt = 0;
            for (int k = 0; k < 4; k++) {
                int next_x = j + dx[k];
                int next_y = i + dy[k];
                if (next_x < 0 || next_x >= C || next_y < 0 || next_y >= R) {
                    cnt++; // 좌표밖은 다 바다임
                }
                    
                else if (map[next_y][next_x] == '.') {
                    cnt++;
                }
            }
            if (cnt >= 3) {
                next_map[i][j] = '.';
            }
        }
    }
    // 이제, 행or열 전체가..... 인 부분들 다 지워버려야함

    
    int minrow, mincol, maxrow, maxcol;
    minrow = R; mincol = C;
    maxrow = 0; maxcol = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (next_map[i][j] == 'X') {
                if (minrow > i) minrow = i;
                if (mincol > j) mincol = j;
                if (maxrow < i) maxrow = i;
                if (maxcol < j) maxcol = j;
            }
        }
    }
    for (int i = minrow; i <= maxrow; i++) {
        for (int j = mincol; j <= maxcol; j++) {
            cout << next_map[i][j];
        }
        cout << endl;
    }


    return 0;
}