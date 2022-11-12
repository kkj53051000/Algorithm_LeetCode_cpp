class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int nowIndex = nums[0];
        int nextIndex = 0;
        
        if (nums.size() <= 1) {
            return true;
        }
        if (nums[0] >= nums.size()-1) {
            return true;
        }

        while(nextIndex < nums.size()-1) {
            int nowValue = nums[nowIndex];

            if (nowValue == 0 && nums.size() > 1) {
                return false;
            } 

            nextIndex = nowValue + nowIndex;
            nowIndex = nextIndex;

        }

        return true;
        
    }
};


// 다음 인덱스가 nums.size()-1 보다 같거나 작을때만 while문 돌립니다.


// [2,5,0,0]가 왜 true인지 모르겠음.
// 왜 dp문제인지 모르겠음.


// 시간복잡도 : O(n)