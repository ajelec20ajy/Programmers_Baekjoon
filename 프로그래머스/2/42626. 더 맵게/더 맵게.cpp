#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    /*
    새 스코빌 : 젤 낮은거 + 2*두번째로 낮은거
    */
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //priority_queue<int> maxHeap;
    
    for(int i : scoville){
        minHeap.push(i);
    }
    int cnt = 0;
    while(!minHeap.empty()){
        if(minHeap.top() >= K) return cnt;
        if(minHeap.size() < 2) return -1;
        int new_scoville = minHeap.top();
        minHeap.pop();
        new_scoville += minHeap.top() * 2;
        minHeap.pop();
        minHeap.push(new_scoville);
        cnt++;
    }
    return -1;
}