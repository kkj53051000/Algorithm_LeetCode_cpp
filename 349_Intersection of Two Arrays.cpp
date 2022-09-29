class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> numCheck;
        
        vector<int> answer;
        
        for (int i = 0; i < nums1.size(); i++) {
            if (numCheck[nums1[i]] == NULL) {
                numCheck[nums1[i]] = true;
            }
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (numCheck[nums2[i]]) {
                answer.push_back(nums2[i]);
                numCheck[nums2[i]] = false;
            }
        }
        
        return answer;
    }
};