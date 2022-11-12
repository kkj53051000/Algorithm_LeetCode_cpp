class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> a_check;
        
        a_check[s[0]] = 0;
        
        int count = 1;
        int maxCount = 0;
        
        if (s.size() == 1) {
            return 1;
        }else if (s.size() == 2 && s[0] != s[1]) {
            return 2;
        }
        
        for (int i = 1 ; i < s.size(); i++) {
            
            std::cout << count;
            if (maxCount < count) {
                maxCount = count;
            }
            
            if ((i-count) == a_check[s[i]]) {
                count = 1;
            }else {                
                count++;
                if (maxCount < count) {
                    maxCount = count;
                }
            }
        
            
            a_check[s[i]] = i;
        }
        
        return maxCount;
    }
};


// a_check map에 최근 만난 char과 index를 넣어줍니다.
// 똑같은 index를 만나게되면 이 index의 전 위치를 파악해서 길이를 측정할 수 있습니다.


// 실패

// 시간복잡도 : O(N)