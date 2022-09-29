class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        set<int> s;
        unordered_map<int, int> counter;
        
        for (int i = 0; i < arr.size(); i++) {
            s.insert(arr[i]);
            
            if (counter[arr[i]] == NULL) {
                counter[arr[i]] = 1;
            }else {
                int temp = counter[arr[i]];
                counter[arr[i]] = temp + 1;
            }
        }
        
        
        unordered_map<int, bool> count_check;
        
        for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
            
            std::cout << *it;
            
            if (count_check[counter[*it]] == NULL) {
                count_check[counter[*it]] = true;
            }else {
                return false;
            }
            
            
        }

        
        return true;
    }
};

// set에 값들 넣고
// map에 몇번나왔는지 넣는다.
// 다 꺼내서 중복이 있는지 확인한다.