class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        queue<vector<int>> que;
        
        // 상, 하, 좌, 우
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        int answerCount = 0;
        
        // 반복문 돌면서 1만날떄 마다 탐색
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                char nowValue = grid[i][j];
                
                if(nowValue == '1') {
                    que.push({i, j});
                    answerCount++;
                }
                
                while(que.size() > 0) {
                    vector<int> xy = que.front();
                    que.pop();
                    
                    int x = xy[0];
                    int y = xy[1];
                    
                    for(vector<int> direction : directions) {
                        // 갈 수 있는지 확인
                        if(x + direction[0] > 0 && x + direction[0] < (grid.size()-1) && y + direction[1] > 0 && y + direction[1] < (grid[x].size()-1) ) {
                            if (grid[(x+direction[0])][(y+direction[1])] == '1') {
                                que.push({x+direction[0], y+direction[1]});
                                // 방문처리
                                grid[(x+direction[0])][(y+direction[1])] = '0';
                            }
                        }
                        
                    }
                }
            }
        }
        
        return answerCount;
    }
};

// 실패

// 시간복잡도 : O(N*N)