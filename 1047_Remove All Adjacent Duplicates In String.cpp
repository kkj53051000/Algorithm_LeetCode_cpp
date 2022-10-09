class Solution {
public:
    string removeDuplicates(string s) {
        
        string answer;
        
        for (int i = 0; i < s.size(); i++) {
            if(answer.size() > 0) {
                if (answer[answer.size()-1] == s[i]) { // arr 마지막 값과 현재값이 같으면 arr.pop()
                    answer.pop_back();
                }else {// 같지 않으면 arr.push()
                    answer.push_back(s[i]);
                }
            }else { // arr.size()가 0이면 arr.push()
                answer.push_back(s[i]);
            }
        }
        
        return answer;
        
    }
};

// 성공

// 시간복잡도 : O(n)
