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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = head;
        
        while(dummy != nullptr && dummy->next != nullptr) {
            if(dummy->val == dummy->next->val) { // 지금 값과 다음 값이 같을 때
                dummy->next = dummy->next->next;  // 다음 주소에 다다음 주소를 넣어준다.
            }else {
                dummy = dummy->next;  // next200. Number of Islands
            }
        }
        
        return head;
    }
};

// 성공

// 시간 복잡도 : O(n)