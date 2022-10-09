class Solution {
public:
    string simplifyPath(string path) {
        
        string answer;
        
        answer.push_back(path[0]);
        
        // 반복문을 돌면서 answer에 값을 push하거나 pop해줍니다.
        for (int i = 1; i < path.size()-1; i++) {
            if(path[i] == '/') {
                if(answer.back() != '/') {
                    answer.push_back('/');
                }
            }else if(path[i] == '.') {
                if(answer.back() == '.') {
                    
                    // 전 디렉토리를 지워야함.
                    int slashCount = 0;
                    
                    while(slashCount != 2 && answer.size() != 1) {
                        if(answer[answer.size()-1] == '/') {
                            answer.pop_back();
                            slashCount++;
                        }else {
                            answer.pop_back();
                        }
                    }
                    
                }
            }else {
                answer.push_back(path[i]);
            }
        }
        
        //마지막 문자가 '/' 또는 '.'가 아니면 push_back()
        if(path.back() != '/' && path.back() != '.') {
          answer.push_back(path.back());
        }
        
        return answer;
    }
};

//실패

// 시간복잡도 : O(NM)