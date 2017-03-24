/*
题目描述
输入一个链表，反转链表后，输出链表的所有元素。
*/

//算法：遍历链表，头插法创建新链表
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode* pre=nullptr; ListNode* next=nullptr;
        while(pHead!=nullptr){
            next=pHead->next;
        	  pHead->next=pre;
        	  pre=pHead;
        	  pHead=next;
        }
        return pre;
    }
};
