class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        vector<char> sArr = removeShap(s);
        
        vector<char> tArr = removeShap(t);
        
        if(sArr == tArr) {
            return true;
        }else {
            return false;
        }
        
    }
    
    vector<char> removeShap(string s) {
        
        vector<char> sArr;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                sArr.push_back(s[i]);
            }else {
                if(sArr.size() > 0) {
                    sArr.pop_back();
                }
            }
        }
        
        return sArr;
    }
};


// #이 나오면 arr.pop() 아니면 arr.push()

// 성공

// 시간복잡도 : O(N)