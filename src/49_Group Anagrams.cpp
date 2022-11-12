class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> strMap;
        
        int count = -1;
        
        vector<vector<string>> answer;
        
        for (int i = 0; i < strs.size(); i++) {
            string nowStr = strs[i];
            string nowSortStr = strs[i];
            std::sort(nowSortStr.begin(), nowSortStr.end());
            
            
            
            
            if (strMap.find(nowSortStr) == strMap.end()) {
                count++;
                strMap[nowSortStr] = count;
                
                answer.push_back({nowStr});
            }else {
                int temp = strMap[nowSortStr];
                
                
                answer[temp].push_back(nowStr);
                
            }
        }
        
        return answer;
        
    }
};


//
// strs의 원소를 정렬해서 맵에 count를 넣어놓습니다.
// 정렬한 원소가 다를때 마다 count에 1씩 더합니다.
// 맵의 숫자에 맞는 배열 위치에 strs의 원소를 넣어줍니다. (map에 strs의 정렬 원소가 없으면 새로운 배열 넣음.)
//
// 시간복잡도 : O(n)
//
// 성공