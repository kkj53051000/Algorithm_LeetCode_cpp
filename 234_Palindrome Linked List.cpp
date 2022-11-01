/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* dump = head;
        
        while(dump) {
            v.push_back(dump->val);
            dump = dump->next;
        }
        
        int vSize = v.size();
        
        for(int i = 0; i < vSize/2; i++) {
            if(v[i] != v[vSize-i-1]) {
                return false;
            }
        }
        
        return true;
    }
};

// success

// v 배열에 전부 넣고 반복문을 돌리면서 v[i]와 v[v.size()-i-1] 과 비교해서 틀리면 false를 return 합니다.

// 시간복잡도 : O(n)