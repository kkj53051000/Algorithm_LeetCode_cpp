#include <algorithm>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        
        int maxValue = 0;
        
        if (nums.back() > nums.size()) {
            maxValue = nums.back();
        }else {
            maxValue = nums.size();
        }
        
        
        for (int i = 0; i < maxValue; i++) {
            if (nums[i] != i) {
                return answer;
            }
            
            answer++;
        }
        
        return answer;
    }
};

//  정렬 -> maxValue 찾아서 반복문 -> 중간에 값없으면 리턴

// 시간복잡도 : O(N)