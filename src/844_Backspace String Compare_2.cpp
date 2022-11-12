class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string sStr = removeShap(s);
        
        string tStr = removeShap(t);
        
        if(sStr == tStr) {
            return true;
        }else {
            return false;
        }
        
    }
    
    string removeShap(string s) {
        
        string sStr;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                sStr.push_back(s[i]);
            }else {
                if(sStr.size() > 0) {
                    sStr.pop_back();
                }
            }
        }
        
        return sStr;
    }
};


// #이 나오면 arr.pop() 아니면 arr.push()

// 성공

// 시간복잡도 : O(N)