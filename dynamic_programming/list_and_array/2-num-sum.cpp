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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head = nullptr,*tail = nullptr;
        int carry = 0;
        while(l1||l2){
            int n1 = l1?l1->val:0;//若l1存在，则将l1中存储的值放入n1中
            int n2 = l2?l2->val:0;
            int sum = n1+n2+carry;
            if(!head){//若头部为空，将创建第一个节点
                head = tail = new ListNode(sum%10);
            }
            else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
            carry = sum /10;//记录下进位的值
            if(l1){
                l1 = l1 ->next;//将进行下一位的运算
            }
            if(l2){
                l2 = l2->next;
            }
            
        }
        if(carry>0){//这里是考虑最后一位的进位
                tail->next = new ListNode(carry);
        }
        return head;
    }
};