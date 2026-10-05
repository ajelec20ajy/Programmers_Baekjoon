#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    
    // 일단 뭐 큐에서 어케 넣을거고, 어케 뺄건지 생각해보자.
    // 일단 넣으려면, jobs에서 완료안되고 요청 시각이 지금 시간 이하인 애들을 넣어야겠지?
    // 뺄때는 pq로 빼면 되고. 근데 이제 빼면서 시각을 기록해야지
    // 그럼 지금 시각이 필요하구요
    // pq도 필요하네요
    // 일단 그러면 jobs를 요청시각으로 정렬해두고싶고요 오름차순이죵
    
    vector<vector<int>> my = jobs;
    for(int i = 0; i < my.size(); i++){
        my[i].push_back(i);
    }
    sort(my.begin(), my.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });
    // my : (1) 요청시간 (2) 작업필요시간 (3) 인덱스
    int start = 0;
    int end = 0;
    int cnt = 0; // 작업 완료한 갯수, ~ my.size();
    int idx = 0; // 대기열에 올린 갯수
    vector<vector<int>> waiting;
    vector<vector<int>> ans;
    int sum = 0;
    while(cnt < my.size()){
        // 넣을 수 있는거 넣기
        int s= idx;
        for(int i = s; i < my.size(); i++){
            if(my[i][0] <= start){
                waiting.push_back(my[i]);
                idx++;
            }
        }

        // 하나 빼기
        // my : (1) 요청시간 (2) 작업필요시간 (3) 인덱스
        if(waiting.size() > cnt){ // 뺄게 있다면 말이지
            sort(waiting.begin()+cnt, waiting.end(), [](vector<int> a, vector<int> b){
                if(a[1] != b[1]) return a[1] < b[1];
                if(a[0] != b[0]) return a[0] < b[0];
                return a[2] < b[2];
            });
            vector<int> tmp;
            tmp = waiting[cnt];
            sum += (start+waiting[cnt][1] - waiting[cnt][0]);
            start += waiting[cnt][1];
            cnt++;
        }
        else{ // 뺄게 없으면 start 조정
            start = my[idx][0];
        }
    }
    
    return sum / jobs.size();
}