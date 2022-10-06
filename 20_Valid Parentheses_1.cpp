#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        
        unordered_map<char, char> match;
        
        match['('] = ')';
        match['{'] = '}';
        match['['] = ']';
        
        if (s.size() == 1) {
            return false;
        }
        
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ')' or s[i] == '}' or s[i] == ']') {
                stack.push(s[i]);
            }else {
                if (stack.size() > 0 && match[s[i]] == stack.top()) {
                    stack.pop();
                }else {
                    return false;
                }
            }
        }
        
        if (stack.size() > 0) {
            return false;
        }        
        
        return true;
    }
};

// 1. 뒤에서부터 하나씩 꺼낸다
// 2. stack에 닫는괄호를 쌓는다. 열린괄호가 나오면 stack.top()으로 확인한다.
// 3. 둘이 같으면 stack.pop()

/*
* 예외
1. s.size() == 1
2. 마지막에 stack.size() > 0
*/

// 시간복잡도 : O(N)

// 성공