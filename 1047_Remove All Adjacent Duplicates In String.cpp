class Solution {
public:
    string removeDuplicates(string s) {
        // 정답 넣을 배열
        vector<char> arr;

        for (int i = 0; i < s.size(); i++) {
            if(arr.size() > 0) {
                if (arr[arr.size()-1] == s[i]) { // arr 마지막 값과 현재값이 같으면 arr.pop()
                    arr.pop_back();
                }else { // 같지 않으면 arr.push()
                    arr.push_back(s[i]);
                }
            }else { // arr.size()가 0이면 arr.push()
                arr.push_back(s[i]);
            }
        }
        
        
        // arr => string
        string str = "";
        
        for (int i = 0; i < arr.size(); i++) {
            str += arr[i];
        }
        
        return str;
        
    }
};


// 성공

// 시간복잡도 : O(n)
