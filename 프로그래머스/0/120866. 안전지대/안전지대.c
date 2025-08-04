#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** board, size_t board_rows, size_t board_cols) {
    for (int i = 0; i < board_rows; i++) {
        for (int j = 0; j < board_cols; j++) {
            if (board[i][j] == 1) {
                
                    if (i != 0 && j != 0 && board[i - 1][j - 1] != 1) board[i - 1][j - 1] = 2;
                    if (i != 0 && board[i - 1][j] != 1) board[i - 1][j] = 2;
                    if (i != 0 && j != board_cols - 1 && board[i - 1][j + 1] != 1) board[i - 1][j + 1] = 2;
                    if (j != 0 && board[i][j - 1] != 1) board[i][j - 1] = 2;
                    if (j != board_cols - 1 && board[i][j + 1] != 1) board[i][j + 1] = 2;
                    if (i != board_rows - 1 && j != 0 && board[i + 1][j - 1] != 1) board[i + 1][j - 1] = 2;
                    if (i != board_rows - 1 && board[i + 1][j] != 1) board[i + 1][j] = 2;
                    if (i != board_rows - 1 && j != board_cols - 1 && board[i + 1][j + 1] != 1) board[i + 1][j + 1] = 2;
                
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < board_rows; i++) {
        for (int j = 0; j < board_cols; j++) {
            if (board[i][j] == 0) cnt++;
        }
    }

    return cnt;
}

/*
음 지뢰가 있는 칸 주변을 그냥 2로 만들고, 칸 값이 1인 개수를 세면 될거같아. 
만약 지뢰가 i, j에 있을 때 있다고 하자.

그럼 상, 하, 좌, 우가 경계를 넘어갈 수도 있겠지? 그럼 그건 빼야되
만약 상단과 하단에 걸려있는 경우라면, i == 0인 경우랑, i == board_rows인 경우지
그리고 만약 좌, 우에 걸려있는 경우라면, j == 0 혹은 j == board_cols이지.

*/