class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int height = grid.size();
        int width = grid[0].size();
        
        queue<pair<int, int>> que;
        
        // 상, 하, 좌, 우
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        int answerCount = 0;
        
        // 반복문 돌면서 1만날떄 마다 탐색
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char nowValue = grid[i][j];
                
                if(nowValue == '1') {
                    que.push({i, j});
                    answerCount++;
                }
                
                while(!que.empty()) {                    
                    int x = que.front().first;
                    int y = que.front().second;
                    
                    que.pop();
                    
                    for(vector<int> direction : directions) {
                        int xx = direction[0];
                        int yy = direction[1];
                        
                        // 갈 수 있는지 확인
                        if(x + xx >= 0 && x + xx <= grid.size() && y + yy >= 0 && y + yy <= grid[x].size() ) {
                            if (grid[(x+xx)][(y+yy)] == '1') {
                                que.push({x+xx, y+yy});
                                
                                // 방문처리
                                grid[(x+xx)][(y+yy)] = '0';
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
// AddressSanitizer: heap-buffer-overflow

// 시간복잡도 : O(N*N)