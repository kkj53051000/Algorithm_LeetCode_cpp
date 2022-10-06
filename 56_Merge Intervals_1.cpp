class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int tempStart = 0;
        int tempEnd = 0;
        
        bool isPush = true;
        
        vector<vector<int>> answer;
        
        sort(intervals.begin(), intervals.end());
        
        for (int i = 0; i < intervals.size()-1; i++) {
            
            if (intervals[i][1] >= intervals[i+1][0]) {
                (intervals[i][0] <= intervals[i+1][0]) ? tempStart = intervals[i][0] : tempStart = intervals[i+1][0];
                (intervals[i][1] >= intervals[i+1][1]) ? tempEnd = intervals[i][1] : tempEnd = intervals[i+1][1];
                
                isPush = false;
                i++;
            }else {
                if (!isPush) {
                    answer.push_back({tempStart, tempEnd});
                    isPush = true;
                }
                
                answer.push_back({intervals[i][0], intervals[i][1]});
            }
            
        }
        
        int intervalsSize = intervals.size();
        
        if (!isPush) {
            
            (tempStart <= intervals[intervalsSize-1][0] ? tempStart = tempStart : tempStart = intervals[intervalsSize-1][0]);
            (tempEnd >= intervals[intervalsSize-1][1] ? tempEnd = tempEnd : tempEnd = intervals[intervalsSize-1][1]);
            
            answer.push_back({tempStart, tempEnd});
        }else {
            answer.push_back({intervals[intervalsSize-1][0], intervals[intervalsSize-1][1]});
        }
        
        
        return answer;
    }
};

// [a, b] [c, d]
// if c >= b  => merge
// b, d 중에 큰 수를 뒤 a, c 중에 작은걸 앞

// 마지막 원소는 따로 집어넣어 줘야함

// 실패 다시 풀어보자.

// 시간복잡도 O(n)