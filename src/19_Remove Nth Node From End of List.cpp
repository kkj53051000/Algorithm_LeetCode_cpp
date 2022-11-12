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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Node가 총 1개일때 
        if(head->next == nullptr) {
            return head->next;
        }

        ListNode* dump1 = head;

        int size = 0;

        while(dump1 != nullptr) {
            size++;
            dump1 = dump1->next;
        }

        ListNode* dump2 = head;

        int count = 0;

        // 길이-n == 0 : 첫번째 노드를 제거하는 경우
        if(size-n == 0) {
            return head->next;
        }

        while(dump2 != nullptr) {
            count++;

            if(count == size-n) {
                dump2->next = dump2->next->next;
                break;
            }
            dump2 = dump2->next;
        }

        return head;
    }
};

// 전체 길이 측정후 뒤에서 n번째 위치 찾아서 제거
// 성공

// 시간복잡도 : O(n)