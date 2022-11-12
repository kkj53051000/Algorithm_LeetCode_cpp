class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int prevIndex = -1;
        int nowIndex = 0; //2
        
        
        if (nums.size() <= 1) {
            return true;
        }
        if (nums[0] >= nums.size()-1) {
            return true;
        }
        
        while(prevIndex != nowIndex) {
            int nowValue = nums[nowIndex];
            
            int nextIndex = nowValue + nowIndex;
            
            prevIndex = nowIndex;
            nowIndex = nextIndex;
            
            if (nowIndex >= nums.size()-1) {
                return true;
            }
        }
        
        return false;
        
    }
};

// 전 인덱스와 지금 인덱스가 같으면 while문을 벗어나고 false를 return 해줍니다. (전 인덱스 == 지금 인덱스 : 이동이 없다.)
// 지금 인덱스가 nums.size()-1 보다 크면 true를 return 해줍니다.
// 
// 시간복잡도 : O(n)

// 실패