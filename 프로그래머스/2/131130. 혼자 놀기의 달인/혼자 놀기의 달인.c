#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cards_len은 배열 cards의 길이입니다.
int solution(int cards[], size_t cards_len) {
    int *arr = (int)malloc(sizeof(int) * cards_len);
    int next;
    int a=0, b=0; int max_score = 0;

   
    for(int i = 0; i<cards_len; i++){ //1번 그룹 처음으로 열 박스 선택
        for(int l = 0; l<cards_len; l++){ //열린 박스인지 체크할 arr 0으로 초기화
            arr[l] = 0;
        }
        arr[i] = 1; next = cards[i]; a=1;
        while(1){ //1번 그룹 지정
            if(arr[next-1]!=1){//안열려있으면
                arr[next-1] = 1; a++; next = cards[next-1]; //박스 열고, 점수  추가, next 지정
            }       
            else if(arr[next-1] == 1){//열려있다면
                break; // 1번그룹지정 반복문 종료
            }
        }
        for(int j = 0; j<cards_len;j++){//2번 그룹 첫빠따 정하기
            int *arr2 = (int)malloc(sizeof(int) * cards_len);
            for(int m = 0; m<cards_len; m++){
                if(arr[m] == 1) arr2[m] = 1;
                else arr2[m] = 0;
            }
            if(arr2[j] != 1){ //열려있지 않은 박스들에 대해서, 열려있으면 b=0임.
                arr2[j] = 1; next = cards[j]; b = 1;
                while(1){
                    if(arr2[next-1]!=1){
                        arr2[next-1] = 1; b++; next = cards[next-1];
                    }
                    else if(arr2[next-1] == 1){
                        break;
                    }
                }
                if(max_score <= a*b) max_score= a*b;
            } 
            
        }
        
    }
    
    return max_score;
}