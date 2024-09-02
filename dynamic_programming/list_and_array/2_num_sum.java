package dynamic_programming.list_and_array;


class ListNode{
    int val;
    ListNode next;
    ListNode(){}
    ListNode(int val){
        this.val = val;
    }
    ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
}
class Solution{
    public ListNode addTowNumber(ListNode l1, ListNode l2){
        ListNode head = null, tail = null;
        // tail指向当前链表的尾部
        int carry = 0;
        while(l1 != null ||l2 != null){
            // 若l1或l2不为空，则计算当前位相加的结果
            int n = l1 != null ? l1.val : 0;//这里注意的是Java判断必须是boolean类型，不能用l1直接作为判断条件
            // 在c++中，如果l1为空
            // int n = l1 ? l1.val : 0;
            // 就可以这样简写，但是java不行
            int m = l2 != null ? l2.val : 0;
            int sum = n + m + carry;
            // 下面将结果放入新节点中
            if(head == null){
                head = tail = new ListNode(sum%10);
            }else{
                tail.next = new ListNode(sum%10);
                tail = tail.next;
            }
            carry = sum/10;
            if(l1 != null){
                l1 = l1.next;
            }
            if(l2 != null){
                l2 = l2.next;
            }
        }
        if(carry == 1){
            tail.next = new ListNode(1);
        }
        return head;
    }
}