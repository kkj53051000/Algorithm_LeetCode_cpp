class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        queue<int> q;
        map<int, bool> visited;

        // q에 시작 위치를 넣어줍니다.
        q.push(source);

        // q가 null이 아닐때 까지 반복
        while(!q.empty()) {
            // q front value
            int now = q.front();
            q.pop();

            // 방문처리
            visited[now] = false;

            // 현재 위치의 연결되어있는 배열 노드 개수만큼 반복문
            for(int i = 0; i < edges[now].size(); i++) {
                1971. Find if Path Exists in Graph

                // 노드 값
                int edge = edges[q.front()][i];

                // 찾는 노드와 지금 노드 비교
                if(edge == destination) {
                    return true;
                }

                // 방문 유무(맵 키 유무), 현재 노드와 now와 같은지 확인
                if(visited.find(edge) != visited.end() && edge != now) {
                    q.push(edges[q.front()][i]);
                }
            }
        }

        return false;
    }
};

// 실패
// runtime error: addition of unsigned offset to 0x608000000020 overflowed to 0x6079e1e1e1f0

// 시간 복잡도 : O(n)