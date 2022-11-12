class Solution {
public:
    string makeGood(string s) {
        vector<char> arr;
        
        
        for (int i = 0; i < s.size(); i++) {
            if(isupper(s[i])) { // 대문자
                if(arr.size() > 0 && islower(arr.back()) && tolower(arr.back()) == tolower(s[i])) {
                    arr.pop_back();
                }else {
                    arr.push_back(s[i]);
                }
            }else {  // 소문자
                if(arr.size() > 0 && isupper(arr.back()) && tolower(arr.back()) == s[i]) {
                    arr.pop_back();
                }else {
                    arr.push_back(s[i]);
                }
            }
        }
        
        string answer = "";
        
        for (char c : arr) {
            answer += c;
        }
        
        return answer;
        
    }
};


// 문제를 정확히 이해하지 못하고 풀어서 삽질을 했었다..

//성공

//시간복잡도 : O(n)