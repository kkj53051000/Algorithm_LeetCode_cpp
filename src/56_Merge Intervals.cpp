class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int tempStart = 0;
        int tempEnd = 0;
        
        bool isPush = true;
        
        vector<vector<int>> answer;
        
        if(intervals.size() <= 1) {
            return intervals;
        }
        
        // sort(intervals.begin(), intervals.end());
        
        for (int i = (intervals.size()-1); i > 0 ; i--) {
            
            
            if (intervals[i][0] <= intervals[i-1][1]) {
                if(intervals[i][0] < intervals[i-1][0]) {
                    tempStart = intervals[i][0];
                }else {
                    tempStart = intervals[i-1][0];
                }
                
                if(intervals[i][1] < intervals[i-1][1]) {
                    if (tempEnd < intervals[i-1][1]) {
                        tempEnd = intervals[i-1][1];
                    }
                }else {
                    if (tempEnd < intervals[i][1]) {
                        tempEnd = intervals[i][1];
                    }
                }
                
                // tempStart = intervals[i-1][0];
                // tempEnd = intervals[i][1];
                
                
                isPush = false;
            } else {
                if (isPush == false) {
                    answer.push_back({tempStart, tempEnd});
                    isPush == true;
                }
                answer.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        
        if (isPush == false) {
            answer.push_back({tempStart, tempEnd});
        }else {
            answer.push_back({intervals[0][0], intervals[0][1]});
        }
        
        return answer;
    }
};

// 접근
// for i를 거꾸로 실행
// intervals[i][0] <= intervals[i-1][1] 이면 tempStart, tempEnd에 값을 넣어놓음
// isPush를 false로 하여 아직 answer에 안넣은것을 표시
// 위 조건문이 아니면 push


// 푸는 방법이 잘못된듯. 처음부터 다시 풀어보자....

// 시간복잡도 O(n)