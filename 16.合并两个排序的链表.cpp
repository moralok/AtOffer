/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

//算法：交替比较
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pHead3=nullptr, *p=nullptr;
        //特殊情况判断
        if (!pHead1 && !pHead2){return NULL;}
        if (!pHead1)return pHead2;
        if (!pHead2)return pHead1;
        //确定新的头结点
        if(pHead1->val<=pHead2->val){
            pHead3=p=pHead1;
            pHead1=pHead1->next;
        }else{
            pHead3=p=pHead2;
            pHead2=pHead2->next;
        }
        //交替比较
        while(pHead1 && pHead2){
            if(pHead1->val <= pHead2->val){              
                 	p->next=pHead1;
            		  pHead1=pHead1->next;           		                 
        	  }else{                
            		  p->next=pHead2;
            		  pHead2=pHead2->next;
        	  }
            p=p->next;
        }
        //剩余段
        if(pHead1){
            p->next=pHead1;
        }else{
            p->next=pHead2;
        }
        
        return pHead3;
        
    }
};
