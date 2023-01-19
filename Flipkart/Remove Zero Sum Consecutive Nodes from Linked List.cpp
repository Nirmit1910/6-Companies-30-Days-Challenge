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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*>m;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode* temp=head;

        m[0]=dummy;

        int sum=0;
        while(temp)
        {
            sum+=temp->val;
            if(m.find(sum)!=m.end())
            {
                ListNode* p=m[sum]->next;
                int vall=sum;
                while(p!=temp)
                {
                    vall+=p->val;
                    m.erase(vall);
                    p=p->next;
                }
                m[sum]->next=temp->next;
            }
            else
            {
                m[sum]=temp;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};