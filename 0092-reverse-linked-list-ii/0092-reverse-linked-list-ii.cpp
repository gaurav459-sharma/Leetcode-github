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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||!head->next)return head;
        
        int i=1;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*pre=dummy;
        ListNode*curr=head;
        ListNode*nextp=NULL;
        while(i<right){
            if(i<left){
                pre=curr;
                curr=curr->next;
            }
            else{
                nextp=curr->next;
                curr->next=curr->next->next;
                nextp->next=pre->next;
                pre->next=nextp;
                    
            }
            i++;
        }
        return dummy->next;
    }
};