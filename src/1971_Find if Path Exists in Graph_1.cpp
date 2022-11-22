class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        queue<int> q;
        map<int, bool> m;

        // 맵 key value 세팅
        for(int i = 0; i < n; i++) {
            m[i] = true;
        }

        // 시작 값 넣기
        q.push(source);

        // 탐색
        while(!q.empty()){
            int qNow = q.front();
            q.pop();

            m[qNow] = false;
            

            if(!m[edges[qNow][0]] && m[edges[qNow][1]]) {
                q.push(edges[qNow][1]);
            }
        }

        // destination을 방문하지 않았으면 return false
        return !m[destination];
    }
};

// 실패
// heap-buffer-overflow 

// 시간 복잡도 : O(n)