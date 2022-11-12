class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string sStr = "";
        
        int count = 0;
        
        for(int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '#') {
                i--;
                i--;
            }else {
                sStr += s[i];
            }
        }
        
        string tStr = "";
        
        for(int i = t.size()-1; i >= 0; i--) {
            if (t[i] == '#') {
                i--;
                i--;
            }else {
                tStr += t[i];
            }
        }
        
        if(sStr == tStr) {
            return true;
        }else {
            return false;
        }
    }
};


// 뒤에서부터 반복분 돌다가 #이 나올때마다 2칸 뒤로감.
// #이 연속해서 나올 수 있기때문에 실패

// 실패

// 시간복잡도 : O(N)