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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(fast->next == nullptr) {
            return head->next;
        }
        
        fast = fast->next->next;
        
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};

// slow는 1칸 fast는 2칸씩 이동시키면서 중간 값을 찾는 식으로 접근.
// fast를 먼저 이동시킨다.
// 중간 바로 전값을 찾아서 중간 바로 다음값을 넣어준다.

// 성공

// 시간복잡도 : O(n)