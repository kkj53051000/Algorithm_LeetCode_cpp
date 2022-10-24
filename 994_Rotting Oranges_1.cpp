#include<queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> queue;
        int count = 0;
        
        // 처음에 썩은 오렌지를 찾는다.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 2) {
                    queue.push({i, j});
                }
            }
        }
        
        // 상, 하, 좌, 우
        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // 썩은 오렌지 주위를 BFS 탐색한다.
        while(queue.size() != 0) {
            
            vector<int> qu = queue.front();
            int x = qu[0];
            int y = qu[1];
            
            queue.pop();
            
            bool goCheck = false;
            
            for(vector<int> d : direction) {
                
                int dx = d[0];
                int dy = d[1];
                
                // 4방향 갈 수 있는지 확인
                if((x + dx) >= 0
                   && (x + dx) <= grid.size()-1
                   && (y + dy) >= 0
                   && (y + dy) <= grid.size()-1
                   && grid[x+dx][y+dy] == 1) {
                    grid[x+dx][y+dy] = 2;
                    queue.push({x+dx, y+dy});
                    
                    goCheck = true;
                }
            }
            
            if(goCheck) {
                count++;
            }
        }
        
        // 다시 전체를 탐색하면서 신선한 오렌지가 있는지 확인한다.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); i++) {
                
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return count;
        
    }
};


// 실패..


// 시간복잡도 : O(n*n)