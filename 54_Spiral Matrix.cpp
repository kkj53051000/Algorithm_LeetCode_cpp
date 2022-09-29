class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<vector<int>> direction = {{0,1}, {-1, 0}, {0, -1}, {1, 0}};
        int nowDirection = 0;
        
        vector<int> answer;
        answer.push_back(matrix[0][0]);
        matrix[0][0] = 1000;
        
        int mx = 0;
        int my = 0;
        
        int count = 0;
        
        int xs = matrix.size(); // x size
        int ys = matrix[mx].size(); // y size
        
        while(answer.size() != (xs*ys)) {
            count++;
                        
            
            int nowDirectionNum = nowDirection % 4;
            
            int px = direction[nowDirectionNum][0]; // 더할 방향
            int py = direction[nowDirectionNum][1]; // 더할 방향
            
            
            
            // 오른 아래 왼 위 모두 갈 수 있고 가는곳이 1000이 아니면 ㄱㄱ
            if(my+py < ys && mx+px < xs && my+py >= 0 && mx+px >= 0 && matrix[mx+px][my+py] != 1000) {
                
                
                matrix[mx][my] = 1000;
                
                mx += px;
                my += py;
                
                answer.push_back(matrix[mx][my]);
            }else {
                nowDirection++;
            }
            
        }
        
        return answer;
        
        
        
        
//         오른, 아래, 왼, 위 순서대로 배열 필요함.
//         장애물을 만날때마다 count++ 해서 방향이 바뀌게 함.
//         방향을 바꿔도 갈 수 없으면 종료
        
        
        
//         direction 안에 뭐를 넣을지 기억이 안나서 vector를 넣음.
        
    }
};