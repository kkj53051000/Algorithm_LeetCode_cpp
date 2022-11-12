class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_map<int, bool> map;
        unordered_map<int, bool> map2;
        
        vector<vector<int>> answer;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    map[i] = true;
                    map2[j] = true;
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (map[i]) {
                    matrix[i][j] = 0;
                }
                if (map2[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};

// 2차원 배열을 돌면서 0 위치를 map에 넣어놓음.
// 2차원 배열을 돌면서 map을 확인해서 0 으로 바꿔줌.

// 시간복잡도 : O(n*n)

// 성공