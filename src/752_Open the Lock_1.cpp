#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> s{begin(deadends), end(deadends)};
        if(s.count("0000")){
            return -1;
        }
        if(target == "0000") {
            return 0;
        }

        queue<pair<string, int>> que;
        que.push({"0000", 0});

        while(!que.empty()) {
            // que값 꺼내기
            pair<string, int> nowValue = que.front();
            que.pop();
            string queValue = nowValue.first;

            // 깊이
            int dep = nowValue.second + 1;;

            // 4개 숫자 모두 더하고 빼서 que에 넣어 줌
            for(int i = 0; i < 4; i++) {
                char nowCache = queValue[i];

                queValue[i] = queValue[i] == '9' ? '0' : queValue[i] + 1;

                if(target == queValue) {
                    return dep;
                }
                // visited 검사 후 push
                if(!s.count(queValue)) {
                    que.push({queValue, dep});
                    s.insert(queValue);
                }

                queValue[i] = nowCache;

                queValue[i] = queValue[i] == '0' ? '9' : queValue[i] - 1;

                if(target == queValue) {
                    return dep;
                }
                if(!s.count(queValue)) {
                    que.push({queValue, dep});
                    s.insert(queValue);
                }

                queValue[i] = nowCache;
            }
        }

        return -1;
    }
};

// 성공

// 시간 복잡도 : O(n)