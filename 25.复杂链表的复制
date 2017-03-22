/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
算法
将问题分解为三部分
1.遍历链表，创建新结点复制后嵌入原结点后面
2.跳跃遍历原链表，判断Random指针并复制
3.遍历整个链表，temp=current->next;current->next=temp->next;current=next;

真的很巧妙啊什么时候我能独立想出这样的算法
*/


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return nullptr;
        //创建新结点并复制
        RandomListNode *currentNode = pHead;
        while(currentNode){
            RandomListNode *node = new RandomListNode(currentNode->label);
            node->next=currentNode->next;
            currentNode->next=node;
            currentNode=node->next;
        }
        //处理Random结点
        currentNode=pHead;
        RandomListNode *node;
        while(currentNode){
            node=currentNode->next;
            if(currentNode->random){
                node->random=currentNode->random->next;
            }
            currentNode=node->next;
        }
        //拆分链表
        RandomListNode *pCloneHead=pHead->next;
        RandomListNode *temp;
        currentNode=pHead;
        while(currentNode->next){
            temp=currentNode->next;
            currentNode->next=temp->next;
            currentNode=temp;
        }
        return pCloneHead;
    }
};
