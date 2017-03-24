/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/

//算法：用两个指针，一个先走k次，另一个跟上，一次遍历即可。
//两次遍历无妨
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	ListNode *pFir=pListHead, *pSec=pListHead;
        unsigned int count=0;
        while(pFir!=NULL){
            pFir = pFir->next;
            if(count>=k){
                pSec = pSec->next;
            }
            count++;
        }
        if(count<k){
            return NULL;
        }
        return pSec;
    }
};
