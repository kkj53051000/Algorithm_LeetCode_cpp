class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        
        vector<vector<int>> answerMap;
        
        for (int i = 0; i < matrix.size(); i++) {
            answerMap.push_back({});
        }
        
        for (int i = matrix.size()-1; i >= 0 ; i--) {
            
            for (int j = 0; j < matrix[i].size(); j++) {
                answerMap[j].push_back(matrix[i][j]);
            }
        
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = answerMap[i][j];
            }
        }
        
    }
};


// answerMap에 3개의 배열을 만들어줌.
// matrix의 맨뒤 원소 배열부터 answerMap의 각각 배열에 한개씩 집어 넣어줌.
// matrix값을 바꾸기 위해서 answer이라는 임시 배열에 넣고 마지막에 matirx값을 바꿔줌.
//
// 시간복잡도 : O(n*n)

// 성공