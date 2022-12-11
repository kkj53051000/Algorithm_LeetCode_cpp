#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        if(target == "0000") {
            return 0;
        }

        vector<string> v;
        
        v.insert(v.end(), deadends.begin(), deadends.end());

        queue<pair<string, int>> que;
        que.push({"0000", 0});

        int depth = 0;

        while(!que.empty()) {
            // que값 꺼내기
            pair<string, int> nowValue = que.front();
            que.pop();
            string queValue = nowValue.first;
            // 방문 처리
            v.push_back(queValue);
            // 깊이
            int dep = nowValue.second + 1;;
            
            // 4개 숫자 모두 더하고 빼서 que에 넣어 줌
            for(int i = 0; i < 4; i++) {
                string plusValue = queValue;
                string minusValue = queValue;

                string nowPlus = to_string(((int)queValue[i] + 1)%10);
                string nowMinus = to_string(((int)queValue[i] - 1)%10);

                plusValue = plusValue.replace(i, 1, nowPlus);
                minusValue =  minusValue.replace(i, 1, nowMinus);

                if(target == plusValue || target == minusValue) {
                    return dep;
                }

                // visited 검사 후 push
                if(find(v.begin(), v.end(), plusValue) == v.end()) {
                    que.push({plusValue, dep});
                    v.push_back(plusValue);
                }

                if(find(v.begin(), v.end(), minusValue) == v.end()) {
                    que.push({minusValue, dep});
                    v.push_back(minusValue);
                }
            }
        }

        return -1;
    }
};

// 실패 (Time Limit Exceeded)

// 시간 복잡도 : O(n)