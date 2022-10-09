class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> answer;
        vector<int> last = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= last[1]) {
                last = {last[0], max(last[1], intervals[i][1])};
            }else {
                answer.push_back(last);
                last = intervals[i];
            }
        }
        
        answer.push_back(last);
        return answer;
    }
};

// 1. 정렬
// 2. last에 intervals[0]을 넣어놓고 시작.
// intervals의 현재와 last와 비교해서 겹치면 max로 큰 값을 찾아서 last의 두번째 인자로 넣어줌.
// 그렇지 않으면 last를 answerdp 넣고 last에 현재 intervals을 넣어줌.

// 정답

// 시간복잡도 O(n)