/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* p = head;
        int n=1;
        while(p->next !=nullptr){
            n++;
            p = p->next;
        }
        p->next = head;
        // n = 5
        // p->next = 1, 此時p在5的位置, 將next設為1則list變為循環的
        k = n - k % n;
        // k = 3
        p = head;
        // p = 1
        while(k-->1){
            p = p->next;
            // step 1: k = 3, p = 2
            // step 2: k = 2, p = 3
        }
        head = p->next;
        // h = 4
        p->next = nullptr;
        // 3 -> NULL
        
        return head;
    }
};

