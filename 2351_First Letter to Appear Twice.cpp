class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> counter;
        
        for (int i = 0; i < s.size(); i++) {
            if (counter[s[i]] == NULL) {
                counter[s[i]] = 1;
            }else if(counter[s[i]] == 1){
                return s[i];
            }
        }
        
        return 'a';
    }
};

// 어떠한 알파벳이 몇번 나왔는지 저장하기 위해 counter hash를 사용합니다.
// 해쉬에 값이 없으면 1을 넣고 값이 1이라면 1이 증가되서 답이기 때문에 바로 return 해줍니다.

// hash에 int를 boolean으로 바꾸면 공간 복잡도가 줄어들것같다.