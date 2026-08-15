class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode* fast=head;
      ListNode* slow=head;
      while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(fast!=slow){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
      }
      return nullptr;
    }
};